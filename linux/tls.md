#### TLS证书

##### 1.先配置nginx和 snap
snap https://snapcraft.io/docs/installing-snap-on-centos
```
sudo dnf install epel-release
sudo dnf upgrade
sudo yum install snapd
sudo systemctl enable --now snapd.socket
sudo ln -s /var/lib/snapd/snap /snap

```
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
##### 3.certbot更新证书后的自动执行脚本
https://eff-certbot.readthedocs.io/en/stable/using.html#pre-and-post-validation-hooks

/etc/letsencrypt/renewal-hooks/post
/etc/letsencrypt/renewal-hooks/deploy


    ssl_certificate /etc/letsencrypt/live/xjianmu.ga/fullchain.pem; # managed by Certbot
    ssl_certificate_key /etc/letsencrypt/live/xjianmu.ga/privkey.pem;


