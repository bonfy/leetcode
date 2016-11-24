# coding:utf-8

import requests
import configparser
import os
import json
import time
from pyquery import PyQuery as pq
import re
import sys


HOME = os.getcwd()
CONFIG_FILE = os.path.join(HOME, 'config.cfg')

# If you have proxy, change PROXIES below
PROXIES = None
HEADERS = {
        'Accept': '*/*',
        'Accept-Encoding': 'gzip,deflate,sdch',
        'Accept-Language': 'zh-CN,zh;q=0.8,gl;q=0.6,zh-TW;q=0.4',
        'Connection': 'keep-alive',
        'Content-Type': 'application/x-www-form-urlencoded',
        'Host': 'leetcode.com',
        'User-Agent':
        'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.152 Safari/537.36'  # NOQA
    }

# TODO: define a class to put file ext and annotation

FILE_EXT = {
    'c++': 'cpp',
    'java': 'java',
    'python': 'py',
    'c': 'c',
    'c#': 'cs',
    'javascript': 'js',
    'ruby': 'rb',
    'swift': 'swift',
    'go': 'go'
}

FILE_ANNO = {
    'c++': '//',
    'java': '//',
    'python': '#',
    'c': '//',
    'c#': '//',
    'javascript': '//',
    'ruby': '#',
    'swift': '//',
    'go': '//'
}


def get_username_password_from_config():
    cp = configparser.ConfigParser()
    cp.read(CONFIG_FILE)

    if 'leetcode' not in list(cp.sections()):
        raise Exception('Please create config.cfg first.')

    username = cp.get('leetcode', 'username')
    password = cp.get('leetcode', 'password')

    if not username or not password:    # username and password not none
        raise Exception('Please input your username and password in config.cfg.')

    language = cp.get('leetcode', 'language')
    if not language:
        language = 'python'    # language default python

    repo = cp.get('leetcode', 'repo')
    if not repo:
        raise Exception('Please input your Github repo address')

    rst = dict(username=username, password=password, language=language.lower(), repo=repo)
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
        code = code.replace(item, chr(int(item[2:], 16)))    # item[2:]去掉\u
    return code


def check_and_make_dir(dirname):
    if not os.path.exists(dirname):
        os.mkdir(dirname)


CONFIG = get_username_password_from_config()


class QuizItem:
    def __init__(self, data):
        self.id = int(data['id'])
        self.title = data['title']
        self.url = data['url']
        self.acceptance = data['acceptance']
        self.difficulty = data['difficulty']
        self.lock = data['lock']
        self.pass_status = True if data['pass'] == 'ac' else False  # 'None', 'ac', 'notac'
        self.article = data['article']
        self.sample_code = None

    def __repr__(self):
        return '<Quiz: {id}-{title}({difficulty})-{pass_status}>'.format(
            id=self.id, title=self.title, difficulty=self.difficulty, pass_status=self.pass_status)


class Leetcode:

    def __init__(self):
        self.items = []
        self.num_solved = 0
        self.num_total = 0
        self.num_lock = 0

        self.solutions = []
        self.language = 'python'

        self.base_url = 'https://leetcode.com'
        self.session = requests.Session()
        self.session.headers.update(HEADERS)
        self.session.proxies = PROXIES
        self.cookies = None
        self.is_login = False

    def login(self):
        login_url = self.base_url + '/accounts/login/'    # NOQA

        if not CONFIG['username'] or not CONFIG['password']:
            raise Exception('Leetcode - Please input your username and password in config.cfg.')

        self.session.get(login_url, proxies=PROXIES)
        token = self.session.cookies['csrftoken']
        print('token:', token)
        login_data = {
            'csrfmiddlewaretoken': token,
            'login': CONFIG['username'],
            'password': CONFIG['password']
        }

        self.session.post(login_url, headers={'Referer': login_url}, proxies=PROXIES, data=login_data)
        if not self.session.cookies.get('PHPSESSID'):
            raise Exception('Login Error')

        self.cookies = dict(self.session.cookies)
        self.is_login = True

    def load(self):
        api_url = self.base_url + '/api/problems/algorithms/'    # NOQA

        if not self.is_login:
            self.login()

        r = self.session.get(api_url, proxies=PROXIES)
        assert r.status_code == 200
        rst = json.loads(r.text)

        # make sure your user_name is not None
        # thus the stat_status_pairs is real
        if not rst['user_name']:
            raise Exception("Something wrong with your personal info.\n")

        self.num_solved = rst['num_solved']
        self.num_total = rst['num_total']
        self.items = list(self._generate_items_from_api(rst))
        self.items.reverse()
        self.num_lock = len([i for i in self.items if i.lock])

    def load_solutions_by_language(self):
        """only load passed solutions by language"""
        pass

    def _generate_items_from_api(self, json_data):
        difficulty = {1: "Easy", 2: "Medium", 3: "Hard"}
        for quiz in json_data['stat_status_pairs']:
            if quiz['stat']['question__hide']:
                continue
            data = {}
            data['title'] = quiz['stat']['question__title_slug']
            data['id'] = quiz['stat']['question_id']
            data['lock'] = not json_data['is_paid'] and quiz['paid_only']
            data['difficulty'] = difficulty[quiz['difficulty']['level']]
            data['favorite'] = quiz['is_favor']
            data['acceptance'] = "%.1f%%" % (float(quiz['stat']['total_acs']) * 100 / float(quiz['stat']['total_submitted']))
            data['url'] = '{base}/problems/{title}'.format(base=self.base_url, title=quiz['stat']['question__title_slug'])
            data['pass'] = quiz['status']
            data['article'] = quiz['stat']['question__article__slug']
            item = QuizItem(data)
            yield item

    def write_readme(self):
        """Write Readme to current folder"""

        md = '''# :pencil2: Leetcode Solutions with {language}
Update time:  {tm}

Auto created by [leetcode_generate](https://github.com/bonfy/leetcode) [Usage](https://github.com/bonfy/leetcode/blob/master/README_leetcode_generate.md)

I have solved **{num_solved}   /   {num_total}** problems
while there are **{num_lock}** problems still locked.

If you have any question, please give me an [issue]({repo}/issues).

If you are loving solving problems in leetcode, please contact me to enjoy it together!

(Notes: :lock: means you need to buy a book from Leetcode to unlock the problem)

| # | Title | Source Code | Article | Difficulty |
|:---:|:---:|:---:|:---:|:---:|'''.format(language=CONFIG['language'],
                                          tm=time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())),
                                          num_solved=self.num_solved, num_total=self.num_total,
                                          num_lock=self.num_lock, repo=CONFIG['repo'])
        md += '\n'
        for item in self.items:
            article = ''
            if item.article:
                article = '[:memo:](https://leetcode.com/articles/{article}/)'.format(article=item.article)
            if item.lock:
                language = ':lock:'
            else:
                if item.pass_status:
                    dirname = '{id}-{title}'.format(id=str(item.id).zfill(3), title=item.title)
                    language = '[{language}]({repo}/blob/master/{dirname}/{title}.{ext})'.format(language=CONFIG['language'], repo=CONFIG['repo'],
                                                                                                 dirname=dirname, title=item.title,
                                                                                                 ext=FILE_EXT[CONFIG['language']])
                else:
                    language = ''

            md += '|{id}|[{title}]({url})|{language}|{article}|{difficulty}|\n'.format(id=item.id, title=item.title,
                                                                                       url=item.url, language=language,
                                                                                       article=article, difficulty=item.difficulty)
        with open('Readme.md', 'w') as f:
            f.write(md)

    def _generate_submissions_by_quiz(self, quiz):
        """Get the answer code by quizItem
        if you have many answers
        choose the code with min run time

        :param quiz: type QuizItem
        """
        submissions_url = 'https://leetcode.com/problems/{title}/submissions/'.format(title=quiz.title)
        # example : 'https://leetcode.com/problems/two-sum/submissions/'
        if not quiz.pass_status:
            raise Exception('Quiz {title} not solve'.format(title=quiz.title))
        r = self.session.get(submissions_url, proxies=PROXIES)
        assert r.status_code == 200
        d = pq(r.text)
        trs = d('table#result-testcases>tbody>tr')
        for idx, tr in enumerate(trs):
            i = pq(tr)
            subTime = i('tr>td:nth-child(1)').text().strip()
            question = i('tr>td:nth-child(2)').text().strip()
            statusText = i('tr>td:nth-child(3)').text().strip()
            status = True if statusText == 'Accepted' else False
            url = self.base_url + i('tr>td:nth-child(3) a').attr('href')
            runText = i('tr>td:nth-child(4)').text().strip()
            runTime = -1 if runText == 'N/A' else int(runText[:-3])
            language = i('tr>td:nth-child(5)').text().strip()

            data = dict(id=idx, subTime=subTime, question=question,
                        status=status, url=url, runTime=runTime, language=language)
            yield data

    def _get_quiz_and_code_by_language(self, quiz):
        submissions_language = [i for i in list(self._generate_submissions_by_quiz(quiz)) if i['language'].lower() == CONFIG['language']]
        submissions = [i for i in submissions_language if i['status']]
        if not submissions:
            print('No pass {language} solution in question:{title}'.format(language=CONFIG['language'], title=quiz.title))
            return None, None

        if len(submissions) == 1:
            sub = submissions[0]
        else:
            sub = min(submissions, key=lambda i: i['runTime'])
        sub_url = sub['url']
        r = self.session.get(sub_url, proxies=PROXIES)
        assert r.status_code == 200
        d = pq(r.text)
        question = d('html>head>meta[name=description]').attr('content').strip()

        pattern = re.compile(r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl', re.S)
        m1 = pattern.search(r.text)
        code = m1.groupdict()['code'] if m1 else None

        if not code:
            raise Exception('Can not find solution code in question:{title}'.format(title=quiz.title))

        code = rep_unicode_in_code(code)

        return question, code

    def download_quiz_code_to_dir(self, quiz):
        question, code = self._get_quiz_and_code_by_language(quiz)
        if not question and not code:
            return
        dirname = '{id}-{title}'.format(id=str(quiz.id).zfill(3), title=quiz.title)
        print('begin download ' + dirname)
        check_and_make_dir(dirname)

        path = os.path.join(HOME, dirname)
        fname = '{title}.{ext}'.format(title=quiz.title, ext=FILE_EXT[CONFIG['language']])
        filename = os.path.join(path, fname)
        # quote question
        # quote_question = '\n'.join(['# '+i for i in question.split('\n')])

        l = []
        for item in question.split('\n'):
            if item.strip() == '':
                l.append(FILE_ANNO[CONFIG['language']])
            else:
                l.append('{anno} {item}'.format(anno=FILE_ANNO[CONFIG['language']], item=item))
        quote_question = '\n'.join(l)

        import codecs
        with codecs.open(filename, 'w', 'utf-8') as f:
            print("begin to write file")
            content = '# -*- coding:utf-8 -*-' + '\n' * 3 if CONFIG['language'] == 'python' else ''
            content += quote_question
            content += '\n' * 3
            content += code
            content += '\n'
            f.write(content)

    def _get_quiz_by_id(self, qid):
        """ get quiz by quiz id

        :param qid: type int
        """
        if not self.items:
            raise Exception("Please load self info first")
        for quiz in self.items:
            if quiz.id == qid:
                return quiz
        raise Exception("No quiz id:{id} find in leetcode.please confirm".format(id=qid))

    def _download_quiz(self, quiz):
        """ download quiz by QuizItem

        :param quiz: type QuizItem
        """
        if not quiz.pass_status:
            print('{id}-{title} not pass'.format(id=quiz.id, title=quiz.title))
        else:
            print('{id}-{title} pass'.format(id=quiz.id, title=quiz.title))
            self.download_quiz_code_to_dir(quiz)

    def download_by_id(self, qid):
        """ download one quiz by quiz id

        :param qid: type int
        """
        quiz = self._get_quiz_by_id(qid)
        self._download_quiz(quiz)

    def download(self):
        """ download all quiz with single thread """
        for quiz in self.items:
            self._download_quiz(quiz)

    def download_with_thread_pool(self):
        """ download all quiz with multi thread """
        from concurrent.futures import ThreadPoolExecutor
        pool = ThreadPoolExecutor(max_workers=4)
        for quiz in self.items:
            pool.submit(self._download_quiz, quiz)
        pool.shutdown(wait=True)


def main():
    leetcode = Leetcode()
    leetcode.login()
    print('Leetcode login')
    leetcode.load()
    print('Leetcode load self info')

    if len(sys.argv) == 1:
        # simple download
        # leetcode.dowload()
        # we use multi thread
        print('download all leetcode solutions')
        leetcode.download_with_thread_pool()
    else:
        for qid in sys.argv[1:]:
            print('begin leetcode by id: {id}'.format(id=qid))
            leetcode.download_by_id(int(qid))

    print('Leetcode finish dowload')
    leetcode.write_readme()
    print('Leetcode finish write readme')


if __name__ == '__main__':
    main()
