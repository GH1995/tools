sudo mv /etc/apt/sources.list /etc/apt/sources.list.bak
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse" >> /etc/apt/sources.list

sudo apt update

# esstenial software, such as, zsh tmux
sudo apt-get install build-essential cmake vim python-dev python3-dev zsh git tmux autojump emacs ctags g++ clang aria2 axel openssh-server openssh-client mysql-server mysql-client texlive-full fontforge latex-cjk-chinese pandoc

# 卸载软件
sudo apt purge xul-ext-ubufox rhythmbox
sudo apt purge libreoffice-core
sudo apt purge libreoffice-*
sudo apt purge unity-webapps-*
sudo apt-get purge thunderbird
sudo apt purge aisleriot transmission-common

# 收尾工作
sudo apt upgrade
sudo apt autoclean
sudo apt autoremove
conda update conda
conda update --all
