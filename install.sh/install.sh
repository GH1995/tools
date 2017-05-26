sudo mv /etc/apt/sources.list /etc/apt/sources.list.bak
echo "# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse" >> /etc/apt/sources.list
echo "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list
echo "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse" >> /etc/apt/sources.list
echo "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse" >> /etc/apt/sources.list
echo "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse" >> /etc/apt/sources.list

echo "# 预发布软件源，不建议启用" >> /etc/apt/sources.list
echo "# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-proposed main restricted universe multiverse" >> /etc/apt/sources.list
echo "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-proposed main restricted universe multiverse" >> /etc/apt/sources.list
sudo apt update

# esstenial software, such as zsh tmux
sudo apt-get install build-essential cmake
sudo apt-get install python-dev python3-dev
sudo apt-get install zsh git tmux autojump
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
git clone https://github.com/gpakosz/.tmux.git
ln -s -f .tmux/.tmux.conf
cp .tmux/.tmux.conf.local ~

# vimrc and zshrc
mkdir  ~/.vim
scp -rP 5102 guanhua@183.174.228.40:~/.vim/vimrc ~/.vim/vimrc
scp -rP 5102 guanhua@183.174.228.40:~/.zshrc ~/.zshrc
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

# install python
mkdir ~/.pip
touch ~/.pip/pip.conf
echo "[global]" >> ~/.pip/pip.conf
echo "index-url = https://pypi.tuna.tsinghua.edu.cn/simple" >> ~/.pip/pip.conf

# Anaconda3
mkdir ~/workspace && cd ~/workspace
wget -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/archive/Anaconda3-4.3.1-Linux-x86_64.sh ~/workspace
bash Anaconda3-4.3.1-Linux-x86_64.sh
echo "# added by Anaconda3 4.3.1 installer" >> ~/.zshrc
echo 'export PATH="$HOME/anaconda3/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes

# deep learning
conda install tensorflow
pip install keras
pip install autopep8
conda update conda
conda update --all

# install latest vim
sudo add-apt-repository ppa:pi-rho/dev
sudo apt update
sudo apt install vim
vim +PluginInstall

# youcomplete me
cd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer

sudo apt upgrade