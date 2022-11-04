###  linux命令

```
kill -9 1414 //杀掉1414进程
lsof -i:443  //查看使用443端口的进程

ll /proc/1414 //查看1414进程的详细信息，
              //cwd符号链接的是进程运行目录，exe符号连接就是执行程序的绝对路径，
              //mdline就是程序运行时输入的命令行命令，environ记录了进程运行时的环境变量

find -name config.json //查找config.json文件
find -name '*config*' //查找文件名含有config的文件

systemctl restart xx.service //启动xx服务
systemctl  enable xx.service //守护进程

tar xvf FileName.tar //解包.tar文件
tar cvf FileName.tar DirName //打包，不是压缩
tar zxvf FileName.tar.gz //解压文件
tar zcvf FileName.tar.gz DirName  //压缩文件


lsb_release -a //系统版本信息
uname -a //内核
cat /proc/version //版本信息


sudo passwd //修改密码

//开启BBR算法，加速TCP
echo "net.core.default_qdisc=fq" >> /etc/sysctl.conf
echo "net.ipv4.tcp_congestion_control=bbr" >> /etc/sysctl.conf
sysctl -p
sysctl net.ipv4.tcp_available_congestion_control //检查开启情况，回显net.ipv4.tcp_available_congestion_control = bbr cubic reno


//cp整个文件夹的文件到另一个文件夹
cp -ri A/B/* A1/B1/ 回车


//ssh 从服务器下载文件
scp username@servername:/path/filename /var/www/local_dir（本地目录）
例如scp root@192.168.0.101:/var/www/test.txt  把192.168.0.101上的/var/www/test.txt 的文件下载到/var/www/local_dir（本地目录）

//ssh 上传文件到服务器
scp /path/filename username@servername:/path   
例如scp /var/www/test.php  root@192.168.0.101:/var/www/  把本机/var/www/目录下的test.php文件上传到192.168.0.101这台服务器上的/var/www/目录中

//ssh 下载文件夹
scp -r username@servername:/var/www/remote_dir/（远程目录） /var/www/local_dir（本地目录）
例如:scp -r root@192.168.0.101:/var/www/test  /var/www/  

//ssh 上传文件夹
scp  -r local_dir username@servername:remote_dir
例如：scp -r test  root@192.168.0.101:/var/www/   把当前目录下的test目录上传到服务器的/var/www/ 目录


``` 

