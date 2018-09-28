# leetcode_generate Usage

![](https://github.com/bonfy/leetcode/blob/master/demo/leetcode.gif)

## Preparements:

Use `selenium` and `chromedriver`

> I think it's not the best way. But I can't find way leetcode encrypt the csrftoken.
> If anyone find the encrypt algoristhm, please pull request to me. And I can change the login to requests

Mac Users can install `Chromedriver` by `Homebrew`

``` cmd
$ brew install chromedriver
```

Centos users install `chromedriver`

```
# Install chromium
$ sudo yum install -y chromium

# Install chromedriver
$ yum install -y chromedriver

# soft link
$ ln -s /usr/bin/chromedriver /usr/local/bin/chromedriver
```

Install essential packages: `requests`, `pyquery`,`selenium`
```cmd
$ pyvenv venv   # create virtual environment
$ source venv/bin/activate
$ pip3 install -r req.txt
```
or if you use Pipenv

```
$ pipenv install
```

## Config:

Edit your own username, password, language and repo in the **config.cfg.example** file and then rename it to **config.cfg**.

driverpath - Please input the path of your chromedriver

```
[leetcode]

username = username
password = password
language = python
repo = https://github.com/bonfy/leetcode
driverpath = /usr/local/bin/chromedriver
```

## Run

### Fully Download
```cmd
python3 leetcode_generate.py
```
Usually you can always run fully download

### Download by id
```
python3 leetcode_generate.py 1
python3 leetcode_generate.py 1 10 100
```
You can only download the solution you want.
Just add the id arguments behind (seperate by space)


## Attention
Python 3 have tested

Python 2 maybe

## Sponsor

![support](http://7i7k6w.com1.z0.glb.clouddn.com/weixin_alipay_new.jpg)

## Changelog

- 2016-10-09 Download codes from Leetcode and generate Readme
- 2016-11-25 Add multi language support
- 2017-01-02 Fix the bug cause by Leetcode change website: `PHPSESSID` change to `LEETCODE_SESSION`
- 2017-04-22 Fix the bug cause by Leetcode change website: csrftoken encrypt, submissions change from HTML to JSON
- 2018-04-02 Modify Phantomjs to Chromedriver. Add time.sleep when download otherwise would be forbidden by leetcode.
- 2018-09-27 Fix the login bug caused by Leetcode change its login page