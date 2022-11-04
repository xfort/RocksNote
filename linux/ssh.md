#### SSH

```
ssh -p 22 root@66.66.66.66 //登录，22为端口号

```

使用scp通过ssh传输文件
```
//远程文件/var/www/test.txt下载到本地/var/www/local_dir
scp root@192.168.0.101:/var/www/test.txt /var/www/local_dir

//上传文件/var/www/test.php到服务端/var/www/
scp /var/www/test.php  root@192.168.0.101:/var/www/

//下载目录
scp -r username@servername:/var/www/remote_dir/ /var/www/local_dir

//上传目录
scp  -r local_dir username@servername:remote_dir
```