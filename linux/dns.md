#### DNS修改

```
nmcli connection show #显示当前网络连接
nmcli  connection modify "System ens192" ipv4.dns "223.5.5.5 8.8.8.8" #修改当前网络连接对应的DNS服务器，这里的网络连接可以用名称或者UUID来标识

nmcli connection up "System ens192" #将dns配置生效
systemctl restart network
nmcli connection reload 

```