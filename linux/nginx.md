#### Nginx 配置


##### 1.Http server https://docs.nginx.com/nginx/admin-guide/web-server/web-server/
官方例子 https://www.nginx.com/resources/wiki/start/topics/examples/full/
centos的nginx配置路径  /etc/nginx/nginx.conf
```
  server { # 
    listen       80;
    server_name  domain1.com www.domain1.com;
    access_log   logs/domain1.access.log  main;
    root         html;
  }
```
#### 2.防火墙开启端口 https://www.cnblogs.com/heqiuyong/p/10460150.html
```
firewall-cmd --zone=public --add-port=5672/tcp --permanent   # 开放5672端口
firewall-cmd --permanent --add-port 60000-61000/tcp  # 开放多个端口
firewall-cmd --zone=public --remove-port=5672/tcp --permanent  #关闭5672端口

firewall-cmd --reload   # 配置立即生效
firewall-cmd --zone=public --list-ports #查看防火墙所有开放的端口
systemctl stop firewalld.service #关闭防火墙

```
