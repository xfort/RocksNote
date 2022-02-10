#### TLS证书

##### 1.先配置nginx和 snap
##### 2.安装certbot https://letsencrypt.org/docs/client-options/
https://certbot.eff.org/instructions?ws=nginx&os=centosrhel8
```
sudo snap install core; sudo snap refresh core
sudo snap install --classic certbot
sudo ln -s /snap/bin/certbot /usr/bin/certbot
sudo certbot --nginx
sudo certbot certonly --nginx #只要证书 不修改nginx
sudo certbot renew --dry-run #自动检测、重新生成

```