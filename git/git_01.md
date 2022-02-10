---
title:"git"
---
## Git 常用命令记录 
[官网文档](https://git-scm.com/book/en/v2)

##### 1.修改 ignore 文件，使其生效
```
git rm -r --cached .
git add .
git commit -m "xxx"
```
##### 2.拉取远程分支到本地/强制覆盖本地
```
//dev为分支名
git fetch origin dev 
git checkout -b dev origin/dev

git fetch --all
git reset --hard origin/dev
git pull
```
##### 3.新建tag
```
git tag -a v1.0 -m ’v1.0版本‘
git push origin v1.0 //git push origin --tags 推送所有
```
##### 4.添加、push多个仓库
```
git remote add xxName xxAddrURL // xxName为自定义别名，xxAddrURL为仓库地址
git remote -V //查看校验
git push xxName xxBranch //推到远程仓库
```
##### 5.设置代理
```
git config --global http.proxy socks5://127.0.0.1:1080
http_proxy=socks5://127.0.0.1:1080 go get github.com/mattn/go-sqlite3
git config --global --unset http.proxy //取消代理
```
##### 6.覆盖远程分支
```
  git push  origin master --force
  git push -f origin master
```
