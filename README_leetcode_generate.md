# leetcode_generate Usage

![](https://github.com/bonfy/leetcode/blob/master/demo/leetcode.gif)

## Preparements:

```cmd
pip install requests
pip install pyquery
```

## Config:

Edit your own username, password, language and repo in the **config.cfg** file

```
[leetcode]

username = username
password = password
language = python
repo = https://github.com/bonfy/leetcode
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

