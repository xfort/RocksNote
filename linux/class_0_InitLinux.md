# linux新系统设置

```
#1 .更改密码
sudo passwd
sudo passwd [username]

#2.添加用户
adduser userX
#3.添加sudo权限
vim /etc/sudoers
usermod -a -G sudo <username>

#4.生成ssh密钥对（要在非root账户下生成），把
ssh-keygen -t rsa

# 禁用密码验证 
PasswordAuthentication no
# 启用密钥验证 
RSAAuthentication yes
PubkeyAuthentication yes
# 指定公钥数据库文件 
AuthorsizedKeysFile .ssh/authorized_keys


#5.修改不SSH配置，禁止root远程登录
vim /etc/ssh/sshd_config

选项参数	                          说明
Host *	                                  选项“Host”只对能够匹配后面字串的计算机有效。“*”表示所有的计算机。
ForwardAgent no	                          设置连接是否经过验证代理（如果存在）转发给远程计算机。
ForwardX11 no	                          设置X11连接是否被自动重定向到安全的通道和显示集（DISPLAY set）
RhostsAuthentication no	                  设置是否使用基于rhosts的安全验证
RhostsRSAAuthentication no	          设置是否使用用RSA算法的基于rhosts的安全验证
RSAAuthentication yes	                  设置是否使用RSA算法进行安全验证
PasswordAuthentication yes	          设置是否使用口令验证
FallBackToRsh no	                  设置如果用ssh连接出现错误是否自动使用rsh
UseRsh no	                          设置是否在这台计算机上使用“rlogin/rsh”
BatchMode no	                          如果设为“yes”，passphrase/password（交互式输入口令）的提示将被禁止。当不能交互式输入口令的时候，这个选项对脚本文件和批处理任务十分有用
CheckHostIP yes	                          设置ssh是否查看连接到服务器的主机的IP地址以防止DNS欺骗。建议设置为“yes”
StrictHostKeyChecking no	          如果设置成“yes”，ssh就不会自动把计算机的密匙加入“$HOME/.ssh/known_hosts”文件，并且一旦计算机的密匙发生了变化，就拒绝连接
IdentityFile ~/.ssh/identity	          设置从哪个文件读取用户的RSA安全验证标识
Port 22	                                  设置连接到远程主机的端口
Cipher blowfish	                          设置加密用的密码
EscapeChar ~	                          设置escape字符


/etc/ssh/sshd_config配置文件

参数选项                                                        说明
Port 22                                                         SSH 预设使用 22 这个 port，您也可以使用多的 port ！
Protocol 2,1                                                    选择的 SSH 协议版本，可以是 1 也可以是 2 ，如果要同时支持两者，就必须要使用 2,1 这个分隔了！
ListenAddress 0.0.0.0                                           监听的主机适配卡！举个例子来说，如果您有两个 IP，分别是 192.168.0.100 及 192.168.2.20 ，那么只想要开放 192.168.0.100 时，就可以写如同下面的样式：
ListenAddress 192.168.0.100                                     只监听来自 192.168.0.100 这个 IP 的SSH联机。如果不使用设定的话，则预设所有接口均接受 SSH
PidFile /var/run/sshd.pid                                       可以放置 SSHD 这个 PID 的档案！左列为默认值
LoginGraceTime 600                                              当使用者连上 SSH server 之后，会出现输入密码的画面，在该画面中，在多久时间内没有成功连上 SSH server ，就断线！时间为秒！
Compression yes                                                 是否可以使用压缩指令？
HostKey /etc/ssh/ssh_host_key                                   SSH version 1 使用的私钥
HostKey /etc/ssh/ssh_host_rsa_key                               SSH version 2 使用的 RSA 私钥
HostKey /etc/ssh/ssh_host_dsa_key                               SSH version 2 使用的 DSA 私钥
KeyRegenerationInterval 3600                                    由前面联机的说明可以知道， version 1 会使用 server 的 Public Key ，每隔一段时间来重新建立一次！时间为秒！
ServerKeyBits 768                                               Server key 的长度！
SyslogFacility AUTH                                             当有人使用 SSH 登入系统的时候，SSH会记录信息
LogLevel INFO                                                   登录记录的等级---》全部
PermitRootLogin no                                              是否允许 root 登入！预设是允许的，但是建议设定成 no！
UserLogin no                                                    在 SSH 底下本来就不接受 login 这个程序的登入！
StrictModes yes                                                 当使用者的 host key 改变之后，Server 就不接受联机
RSAAuthentication yes                                           是否使用纯的 RSA 认证！？仅针对 version 1 ！
PubkeyAuthentication yes                                        是否允许 Public Key ？只有 version 2
AuthorizedKeysFile   .ssh/authorized_keys                       设定若要使用不需要密码登入的账号时，那么那个账号的存放档案所在档名！
RhostsAuthentication no                                         本机系统不使用 .rhosts ， .rhosts 不安全！
IgnoreRhosts yes                                                是否取消使用 ~/.ssh/.rhosts 来做为认证！
RhostsRSAAuthentication no                                      针对 version 1 ，使用 rhosts 档案在/etc/hosts.equiv配合 RSA 演算方式来进行认证！
HostbasedAuthentication no                                      这个项目与上面的项目类似，不过是给 version 2 使用的！
IgnoreUserKnownHosts no                                         是否忽略家目录内的 ~/.ssh/known_hosts 这个档案所记录的主机内容
PasswordAuthentication yes                                      密码验证当然是需要的！
PermitEmptyPasswords no                                         上面那一项如果设定为 yes 的话，这一项就最好设定为 no ，这个项目在是否允许以空的密码登入！
ChallengeResponseAuthentication yes                             挑战任何的密码认证！所以，任何 login.conf 规定的认证方式，均可适用！
PAMAuthenticationViaKbdInt yes                                  是否启用其它的 PAM 模块！启用这个模块将会导致 PasswordAuthentication 设定失效！

与Kerberos 有关的参数设定！底下不用设定
KerberosAuthentication no
KerberosOrLocalPasswd yes
KerberosTicketCleanup yes
KerberosTgtPassing no

有关在 X-Window 底下使用的相关设定
X11Forwarding yes
X11DisplayOffset 10
X11UseLocalhost yes

PrintMotd no                                                    登入后是否显示出一些信息呢？例如上次登入的时间、地点等，预设是 yes ，但是，如果为了安全，可以考虑改为 no ！
PrintLastLog yes                                                显示上次登入的信息！预设也是 yes 
KeepAlive yes                                                   一般而言，如果设定这项目的话，那么 SSH Server 会传送KeepAlive 的讯息给 Client 端，以确保两者的联机正常！在这个情况下，任何一端死掉后， SSH 可以立刻知道！而不会有僵尸程序的发生！
UsePrivilegeSeparation yes                                      使用者的权限设定项目！
MaxStartups 10                                                  同时允许几个尚未登入的联机画面
DenyUsers *                                                     设定受抵挡的使用者名称
AllowUsers *                                                    设定允许的使用者名称
```
#### 6 dnf更新加速
修改 /etc/dnf/dnf.conf 文件，新增两行
```
max_parallel_downloads=10
fastestmirror=True
```
最后 
```
sudo dnf upgrade --refresh
```

#### 7 GNOME插件
隐藏头部标题栏 https://extensions.gnome.org/extension/545/hide-top-bar/
底部任务栏 https://extensions.gnome.org/extension/602/window-list/

#### 8 Fedora36 安装NVIDIA驱动，一定要选择显卡对应的驱动版本号！！！
开启rpmfusion https://rpmfusion.org/Howto/NVIDIA
fedora安装教程 https://docs.fedoraproject.org/en-US/quick-docs/how-to-set-nvidia-as-primary-gpu-on-optimus-based-laptops/
```
开启rpmfusion
sudo dnf install https://mirrors.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm https://mirrors.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm

sudo dnf upgrade --refresh
升级后重启系统选择最新内核版本
sudo dnf install gcc kernel-headers kernel-devel 
选择自己显卡对应的驱动版本，例如我的显卡型号K1100M 对应 470xx

sudo dnf install akmod-nvidia-470xx xorg-x11-drv-nvidia-470xx xorg-x11-drv-nvidia-470xx-libs xorg-x11-drv-nvidia-470xx-libs.i686  sudo dnf install xorg-x11-drv-nvidia-470xx-cuda 
等待结束
sudo akmods --force
sudo dracut --force
重启，验证
```