```shell
#!/bin/bash
# Author: GH1995

## USTC resource
sudo sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list
sudo apt update
sudo apt install curl -y
echo "install USTC resource success!"

# git
sudo apt install git -y
echo "install git success!"


# zsh
sudo apt install bash -y
sudo apt install wget -y
sudo apt install zsh -y
sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
echo "install oh-my-zsh success!"


# 安装Vim和Emacs
sudo apt install vim ctags -y
sudo apt install vim-gnome -y
touch ~/.vimrc
echo "install Vim success!"

sudo apt install emacs -y
echo "install Emacs success!"

# 安装Vundle
# Vundle is short for Vim bundle and is a Vim plugin manager.
$ git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
echo "install Vundle success, but reminder!"

# 安装编译器
sudo apt install g++ -y
sudo apt install clang -y
sudo apt install openjdk-8-jdk -y
echo "install g++, clang, openjdk-8-jdk success!"

# 安装下载工具
sudo apt install aria2 -y
sudo apt install axel -y
echo "install aria2 and axel success!"

# 安装其他工具
sudo apt install tree -y
sudo apt install lynx -y
sudo apt install htop -y
echo "install tree, lynx and htop success!"


# 安装 screen
sudo apt install screen -y
# alt加方向键在相邻终端格之间转移
# -dmS 创建会话 C+A+D离开 -r 恢复 -l 列表
echo "install screen success!"



# 安装openssh-server openssh-client
sudo apt install openssh-server openssh-client -y
# 停止服务：sudo /etc/init.d/ssh stop
# 启动服务：sudo /etc/init.d/ssh start
# 重启服务：sudo /etc/init.d/sshresart
# 断开连接：exit
# 登录：ssh [-l login_name] [-p port] [user@]hostname
echo "install openssh-server and openssh-server success!"


# 安装MySQL
sudo apt install mysql-server mysql-client
# mysql -uroot -p 		登录
# sudo start mysql 		启动MySQL服务
# sudo stop mysql 		停止MySQL服务
# sudo mysqladmin -u root password newpassword 修改 MySQL 的管理员密码
# 数据库存放目录：		/var/lib/mysql/
# 相关配置文件存放目录：/usr/share/mysql
# 相关命令存放目录： /usr/bin(mysqladmin mysqldump等命令)
# 启动脚步存放目录： /etc/rc.d/init.d/
echo "install MySQL success!"


# --------------------------------------------------------------------------
# 可选的一些工具和配置

# fish
# The user-friendly command line shell. http://fishshell.com
sudo apt install fish

# 中文文档[已过时]
# sudo apt install manpages-zh -y

# vim的配置
# sh <(curl https://j.mp/spf13-vim3 -L)

# spacemacs的配置
# git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d

# --------------------------------------------------------------------------

source ~/.bashrc

# upgrade
sudo apt upgrade > /dev/null

echo "EVERYTHING IS OK!"

exit
```
