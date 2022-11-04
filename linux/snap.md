### centosStream9 安装snap  https://snapcraft.io/docs/installing-snap-on-centos
```
#新增源 https://docs.fedoraproject.org/en-US/epel/#_el9
dnf config-manager --set-enabled crb
dnf install \
    https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm \
    https://dl.fedoraproject.org/pub/epel/epel-next-release-latest-9.noarch.rpm 

sudo dnf install snapd
sudo systemctl enable --now snapd.socket
sudo ln -s /var/lib/snapd/snap /snap

```