# coding:utf-8
#
# Author: BONFY<foreverbonfy@163.com>
# Github: https://github.com/bonfy
# Repo:   https://github.com/bonfy/leetcode
# Usage:  Leetcode solution downloader and auto generate readme
#
import requests
import configparser
import os
import json
import time
import datetime
import re
import sys
import html

from selenium import webdriver
from collections import namedtuple, OrderedDict

HOME = os.getcwd()
CONFIG_FILE = os.path.join(HOME, 'config.cfg')
COOKIE_PATH = 'cookies.json'
BASE_URL = 'https://leetcode.com'
# If you have proxy, change PROXIES below
PROXIES = None
HEADERS = {
    'Accept': '*/*',
    'Accept-Encoding': 'gzip,deflate,sdch',
    'Accept-Language': 'zh-CN,zh;q=0.8,gl;q=0.6,zh-TW;q=0.4',
    'Connection': 'keep-alive',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Host': 'leetcode.com',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.152 Safari/537.36',  # NOQA
}


def get_config_from_file():
    cp = configparser.ConfigParser()
    cp.read(CONFIG_FILE)
    if 'leetcode' not in list(cp.sections()):
        raise Exception('Please create config.cfg first.')

    username = cp.get('leetcode', 'username')
    if os.getenv('leetcode_username'):
        username = os.getenv('leetcode_username')
    password = cp.get('leetcode', 'password')
    if os.getenv('leetcode_password'):
        password = os.getenv('leetcode_password')
    if not username or not password:  # username and password not none
        raise Exception(
            'Please input your username and password in config.cfg.'
        )

    language = cp.get('leetcode', 'language')
    if not language:
        language = 'python'  # language default python
    repo = cp.get('leetcode', 'repo')
    if not repo:
        raise Exception('Please input your Github repo address')

    driverpath = cp.get('leetcode', 'driverpath')
    rst = dict(
        username=username,
        password=password,
        language=language.lower(),
        repo=repo,
        driverpath=driverpath,
    )
    return rst


def rep_unicode_in_code(code):
    """
    Replace unicode to str in the code
    like '\u003D' to '='
    :param code: type str
    :return: type str
    """
    pattern = re.compile('(\\\\u[0-9a-zA-Z]{4})')
    m = pattern.findall(code)
    for item in set(m):
        code = code.replace(item, chr(int(item[2:], 16)))  # item[2:]去掉\u
    return code


def check_and_make_dir(dirname):
    if not os.path.exists(dirname):
        os.mkdir(dirname)


ProgLang = namedtuple('ProgLang', ['language', 'ext', 'annotation'])
ProgLangList = [
    ProgLang('cpp', 'cpp', '//'),
    ProgLang('java', 'java', '//'),
    ProgLang('python', 'py', '#'),
    ProgLang('python3', 'py', '#'),
    ProgLang('c', 'c', '//'),
    ProgLang('csharp', 'cs', '//'),
    ProgLang('javascript', 'js', '//'),
    ProgLang('ruby', 'rb', '#'),
    ProgLang('kotlin', 'kt', '//'),
    ProgLang('swift', 'swift', '//'),
    ProgLang('golang', 'go', '//'),
]
ProgLangDict = dict((item.language, item) for item in ProgLangList)
CONFIG = get_config_from_file()


class QuizItem:
    """ QuizItem """
    base_url = BASE_URL

    def __init__(self, **data):
        self.__dict__.update(data)
        self.solutions = []

    def __str__(self):
        return '<Quiz: {question_id}-{question__title_slug}({difficulty})-{is_pass}>'.format(
            question_id=self.question_id,
            question__title_slug=self.question__title_slug,
            difficulty=self.difficulty,
            is_pass=self.is_pass,
        )

    def __repr__(self):
        return self.__str__()

    @property
    def json_object(self):
        addition_properties = [
            'is_pass', 'difficulty', 'is_lock', 'url', 'acceptance'
        ]
        dct = self.__dict__
        for prop in addition_properties:
            dct[prop] = getattr(self, prop)
        return dct

    @property
    def is_pass(self):
        return True if self.status == 'ac' else False

    @property
    def difficulty(self):
        difficulty = {1: "Easy", 2: "Medium", 3: "Hard"}
        return difficulty[self.level]

    @property
    def is_lock(self):
        return not self.is_favor and self.paid_only

    @property
    def url(self):
        return '{base_url}/problems/{question__title_slug}'.format(
            base_url=self.base_url,
            question__title_slug=self.question__title_slug,
        )

    @property
    def acceptance(self):
        return '%.1f%%' % (
            float(self.total_acs) * 100 / float(self.total_submitted)
        )


class Leetcode:

    def __init__(self):
        self.items = []
        self.submissions = []
        self.num_solved = 0
        self.num_total = 0
        self.num_lock = 0
        # change proglang to list
        # config set multi languages
        self.languages = [x.strip() for x in CONFIG['language'].split(',')]
        proglangs = [
            ProgLangDict[x.strip()] for x in CONFIG['language'].split(',')
        ]
        self.prolangdict = dict(zip(self.languages, proglangs))
        self.base_url = BASE_URL
        self.session = requests.Session()
        self.session.headers.update(HEADERS)
        self.session.proxies = PROXIES
        self.cookies = None

    def login(self):
        LOGIN_URL = self.base_url + '/accounts/login/'  # NOQA
        if not CONFIG['username'] or not CONFIG['password']:
            raise Exception(
                'Leetcode - Please input your username and password in config.cfg.'
            )

        usr = CONFIG['username']
        pwd = CONFIG['password']
        # driver = webdriver.PhantomJS()
        options = webdriver.ChromeOptions()
        options.add_argument('headless')
        options.add_argument('--disable-gpu')
        executable_path = CONFIG.get('driverpath')
        driver = webdriver.Chrome(
            chrome_options=options, executable_path=executable_path
        )
        driver.get(LOGIN_URL)
        driver.find_element_by_id('id_login').send_keys(usr)
        driver.find_element_by_id('id_password').send_keys(pwd)
        # driver.find_element_by_id('id_remember').click()
        driver.find_element_by_xpath('//button[@type="submit"]').click()
        time.sleep(5)
        webdriver_cookies = driver.get_cookies()
        driver.close()
        if 'LEETCODE_SESSION' not in [
            cookie['name'] for cookie in webdriver_cookies
        ]:
            raise Exception('Please check your config or your network.')

        with open(COOKIE_PATH, 'w') as f:
            json.dump(webdriver_cookies, f, indent=2)
        self.cookies = {
            str(cookie['name']): str(cookie['value'])
            for cookie in webdriver_cookies
        }
        self.session.cookies.update(self.cookies)

    def load_items_from_api(self):
        """ load items from api"""
        api_url = self.base_url + '/api/problems/algorithms/'  # NOQA
        r = self.session.get(api_url, proxies=PROXIES)
        assert r.status_code == 200
        rst = json.loads(r.text)
        # make sure your user_name is not None
        # thus the stat_status_pairs is real
        if not rst['user_name']:
            raise Exception("Something wrong with your personal info.\n")

        self.items = []  # destroy first ; for sake maybe needn't
        self.num_solved = rst['num_solved']
        self.num_total = rst['num_total']
        self.items = list(self._generate_items_from_api(rst))
        self.num_lock = len([i for i in self.items if i.is_lock])
        self.items.reverse()

    def load(self):
        """
        load: all in one

        login -> load api -> load submissions -> solutions to items
        return `all in one items`
        """
        # if cookie is valid, get api_url twice
        # TODO: here can optimize
        if not self.is_login:
            self.login()
        self.load_items_from_api()
        self.load_submissions()
        self.load_solutions_to_items()

    def _generate_items_from_api(self, json_data):
        stat_status_pairs = json_data['stat_status_pairs']
        for quiz in stat_status_pairs:
            if quiz['stat']['question__hide']:
                continue

            data = {}
            data['question__title_slug'] = quiz['stat']['question__title_slug']
            data['question__title'] = quiz['stat']['question__title']
            data['question__article__slug'] = quiz['stat'][
                'question__article__slug'
            ]
            # data['is_paid'] = json_data['is_paid']
            data['paid_only'] = quiz['paid_only']
            data['level'] = quiz['difficulty']['level']
            data['is_favor'] = quiz['is_favor']
            data['total_acs'] = quiz['stat']['total_acs']
            data['total_submitted'] = quiz['stat']['total_submitted']
            data['question_id'] = quiz['stat']['question_id']
            data['status'] = quiz['status']
            item = QuizItem(**data)
            yield item

    @property
    def is_login(self):
        """ validate if the cookie exists and not overtime """
        api_url = self.base_url + '/api/problems/algorithms/'  # NOQA
        if not os.path.exists(COOKIE_PATH):
            return False

        with open(COOKIE_PATH, 'r') as f:
            webdriver_cookies = json.load(f)
        self.cookies = {
            str(cookie['name']): str(cookie['value'])
            for cookie in webdriver_cookies
        }
        self.session.cookies.update(self.cookies)
        r = self.session.get(api_url, proxies=PROXIES)
        if r.status_code != 200:
            return False

        data = json.loads(r.text)
        return 'user_name' in data and data['user_name'] != ''

    def load_submissions(self):
        """ load all submissions from leetcode """
        # set limit a big num
        limit = 20
        offset = 0
        while True:
            submissions_url = '{}/api/submissions/?format=json&limit={}&offset={}'.format(
                self.base_url, limit, offset
            )
            resp = self.session.get(submissions_url, proxies=PROXIES)
            assert resp.status_code == 200
            data = resp.json()
            if 'has_next' not in data.keys():
                raise Exception('Get submissions wrong, Check network\n')

            self.submissions += data['submissions_dump']
            if data['has_next']:
                offset += limit
            else:
                break

    def load_solutions_to_items(self):
        """
        load all solutions to items

        combine submission's `runtime` `title` `lang` `submission_url` to items
        """
        titles = [i.question__title for i in self.items]
        itemdict = OrderedDict(zip(titles, self.items))

        def make_sub(sub):
            return dict(
                runtime=int(sub['runtime'][:-3]),
                title=sub['title'],
                lang=sub['lang'],
                submission_url=self.base_url + sub['url'],
            )

        ac_subs = [
            make_sub(sub)
            for sub in self.submissions
            if sub['status_display'] == 'Accepted'
        ]

        def remain_shortesttime_submissions(submissions):
            submissions_dict = {}
            for item in submissions:
                k = '{}-{}'.format(item['lang'], item['title'])
                if k not in submissions_dict.keys():
                    submissions_dict[k] = item
                else:
                    old = submissions_dict[k]
                    if item['runtime'] < old['runtime']:
                        submissions_dict[k] = item
            return list(submissions_dict.values())

        shortest_subs = remain_shortesttime_submissions(ac_subs)
        for solution in shortest_subs:
            title = solution['title']
            if title in itemdict.keys():
                itemdict[title].solutions.append(solution)

    def _get_code_by_solution(self, solution):
        """
        get code by solution

        solution: type dict
        """
        solution_url = solution['submission_url']
        print(solution_url)
        r = self.session.get(solution_url, proxies=PROXIES)
        assert r.status_code == 200
        pattern = re.compile(
            r'<meta name=\"description\" content=\"(?P<question>.*)\" />\n    \n    <meta property=\"og:image\"',
            re.S,
        )
        m1 = pattern.search(r.text)
        question = m1.groupdict()['question'] if m1 else None
        if not question:
            raise Exception(
                'Can not find question descript in question:{title}'.format(
                    title=solution['title']
                )
            )

        # html.unescape to remove &quot; &#39;
        question = html.unescape(question)
        pattern = re.compile(
            r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl', re.S
        )
        m1 = pattern.search(r.text)
        code = m1.groupdict()['code'] if m1 else None
        if not code:
            raise Exception(
                'Can not find solution code in question:{title}'.format(
                    title=solution['title']
                )
            )

        code = rep_unicode_in_code(code)
        return question, code

    def _get_code_with_anno(self, solution):
        question, code = self._get_code_by_solution(solution)
        language = solution['lang']
        # generate question with anno
        lines = []
        for line in question.split('\n'):
            if line.strip() == '':
                lines.append(self.prolangdict[language].annotation)
            else:
                lines.append(
                    '{anno} {line}'.format(
                        anno=self.prolangdict[language].annotation,
                        line=html.unescape(line),
                    )
                )
        quote_question = '\n'.join(lines)
        # generate content
        content = '# -*- coding:utf-8 -*-' + '\n' * 3 if language == 'python' else ''
        content += quote_question
        content += '\n' * 3
        content += code
        content += '\n'
        return content

    def _download_code_by_quiz(self, quiz):
        """
        Download code by quiz
        quiz: type QuizItem
        """
        qid = quiz.question_id
        qtitle = quiz.question__title_slug
        slts = list(
            filter(lambda i: i['lang'] in self.languages, quiz.solutions)
        )
        if not slts:
            print(
                'No solution with the set languages in question:{}-{}'.format(
                    qid, qtitle
                )
            )
            return

        dirname = '{id}-{title}'.format(id=str(qid).zfill(3), title=qtitle)
        print('begin download ' + dirname)
        check_and_make_dir(dirname)
        path = os.path.join(HOME, dirname)
        for slt in slts:
            fname = '{title}.{ext}'.format(
                title=qtitle, ext=self.prolangdict[slt['lang']].ext
            )
            filename = os.path.join(path, fname)
            content = self._get_code_with_anno(slt)
            import codecs

            with codecs.open(filename, 'w', 'utf-8') as f:
                print('write to file ->', fname)
                f.write(content)

    def _find_item_by_quiz_id(self, qid):
        """
        find the item by quiz id
        """
        lst = list(filter(lambda x: x.question_id == qid, self.items))
        if len(lst) == 1:
            return lst[0]

        print('No exits quiz id:', qid)

    def download_by_id(self, qid):
        quiz = self._find_item_by_quiz_id(qid)
        if quiz:
            self._download_code_by_quiz(quiz)

    def download(self):
        """ download all solutions with single thread """
        ac_items = [i for i in self.items if i.is_pass]
        for quiz in ac_items:
            time.sleep(1)
            self._download_code_by_quiz(quiz)

    def download_with_thread_pool(self):
        """ download all solutions with multi thread """
        ac_items = [i for i in self.items if i.is_pass]
        from concurrent.futures import ThreadPoolExecutor

        pool = ThreadPoolExecutor(max_workers=4)
        for quiz in ac_items:
            pool.submit(self._download_code_by_quiz, quiz)
        pool.shutdown(wait=True)

    def write_readme(self):
        """Write Readme to current folder"""
        languages_readme = ','.join([x.capitalize() for x in self.languages])
        md = '''# :pencil2: Leetcode Solutions with {language}
Update time:  {tm}

Auto created by [leetcode_generate](https://github.com/bonfy/leetcode)

I have solved **{num_solved}   /   {num_total}** problems
while there are **{num_lock}** problems still locked.

If you want to use this tool please follow this [Usage Guide](https://github.com/bonfy/leetcode/blob/master/README_leetcode_generate.md)

If you have any question, please give me an [issue]({repo}/issues).

If you are loving solving problems in leetcode, please contact me to enjoy it together!

(Notes: :lock: means you need to buy a book from Leetcode to unlock the problem)

| # | Title | Source Code | Article | Difficulty |
|:---:|:---:|:---:|:---:|:---:|'''.format(
            language=languages_readme,
            tm=time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())),
            num_solved=self.num_solved,
            num_total=self.num_total,
            num_lock=self.num_lock,
            repo=CONFIG['repo'],
        )
        md += '\n'
        for item in self.items:
            article = ''
            if item.question__article__slug:
                article = '[:memo:](https://leetcode.com/articles/{article}/)'.format(
                    article=item.question__article__slug
                )
            if item.is_lock:
                language = ':lock:'
            else:
                if item.solutions:
                    dirname = '{id}-{title}'.format(
                        id=str(item.question_id).zfill(3),
                        title=item.question__title_slug,
                    )
                    language = ''
                    language_lst = [
                        i['lang']
                        for i in item.solutions
                        if i['lang'] in self.languages
                    ]
                    while language_lst:
                        lan = language_lst.pop()
                        language += '[{language}]({repo}/blob/master/{dirname}/{title}.{ext})'.format(
                            language=lan.capitalize(),
                            repo=CONFIG['repo'],
                            dirname=dirname,
                            title=item.question__title_slug,
                            ext=self.prolangdict[lan].ext,
                        )
                        language += ' '
                else:
                    language = ''
            language = language.strip()
            md += '|{id}|[{title}]({url})|{language}|{article}|{difficulty}|\n'.format(
                id=item.question_id,
                title=item.question__title_slug,
                url=item.url,
                language=language,
                article=article,
                difficulty=item.difficulty,
            )
        with open('README.md', 'w') as f:
            f.write(md)

    def push_to_github(self):
        strdate = datetime.datetime.now().strftime('%Y-%m-%d')
        cmd_git_add = 'git add .'
        cmd_git_commit = 'git commit -m "update at {date}"'.format(
            date=strdate
        )
        cmd_git_push = 'git push -u origin master'
        os.system(cmd_git_add)
        os.system(cmd_git_commit)
        os.system(cmd_git_push)


def do_job(leetcode):
    leetcode.load()
    print('Leetcode load self info')
    if len(sys.argv) == 1:
        # simple download
        # leetcode.dowload()
        # we use multi thread
        print('download all leetcode solutions')
        # leetcode.download_with_thread_pool()
        leetcode.download()
    else:
        for qid in sys.argv[1:]:
            print('begin leetcode by id: {id}'.format(id=qid))
            leetcode.download_by_id(int(qid))
    print('Leetcode finish dowload')
    leetcode.write_readme()
    print('Leetcode finish write readme')
    leetcode.push_to_github()
    print('push to github')


if __name__ == '__main__':
    leetcode = Leetcode()
    while True:
        do_job(leetcode)
        time.sleep(24 * 60 * 60)
