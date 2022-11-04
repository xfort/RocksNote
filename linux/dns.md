#### DNS修改

##### 1.修改DNS
```
nmcli connection show #显示当前网络连接
nmcli  connection modify "System ens192" ipv4.dns "223.5.5.5 8.8.8.8" #修改当前网络连接对应的DNS服务器，这里的网络连接可以用名称或者UUID来标识

nmcli connection up "System ens192" #将dns配置生效
systemctl restart network
nmcli connection reload 
```

##### 2.修改HOST
在https://ipaddress.com/website/raw.githubusercontent.com 查找真实IP，修改  /etc/hosts 文件

