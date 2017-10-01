# 1 		install
cd
sudo apt install git zsh texlive-full build-essential cmake tmux autojump emacs ctags g++ aria2 axel pandoc lrzsz nload command-not-found htop npm nethogs clang iotop iftop build-essential software-properties-common cron-apt
git config --global user.email tulingjiaoyu@gmail.com
git config --global user.name GuanHua
git config --global push.default simple
cd

# 2			oh my zsh
cd
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"

# 3 	dotfile
cd
git clone git@github.com:GH1995/dotfile.git
bash ~/dotfile/install.sh

# 4 		vim
cd
sudo add-apt-repository ppa:jonathonf/vim -y && \
sudo apt update && \
sudo apt install vim
git clone https://github.com/GH1995/vimrc.git ~/.vim/vimrc && \
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim && \
ln ~/.vim/vimrc/vimrc_real ~/.vimrc && \
vim +PluginInstall +qall && \
cd ~/.vim/bundle/YouCompleteMe && git submodule update --init --recursive && \
./install.py --clang-completer

# 5 		miniconda
cd
wget -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-4.3.21-Linux-x86_64.sh
bash Miniconda3-4.3.21-Linux-x86_64.sh # 需要输入
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes
pip install tensorflow keras autopep8 cheat mycli ici unidecode pillow fanyi

# 6 		GCC
cd
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
sudo apt-get update && \
sudo apt-get install gcc-snapshot -y && \
sudo apt-get update && \
sudo apt-get install gcc-6 g++-6 -y && \
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6

# 			fonts
cd
scp -rP 5102 guanhua@183.174.228.40:~/backup/home/.fonts ~
cd ~/.fonts && fc-cache -fv

# 			spacemacs
cd
git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d

# 			blog
cd ~/workspace && mkdir blog
cd ~/workspace/blog
sudo apt-get install nodejs-legacy
sudo npm install hexo-cli -g
hexo init

# 7			end
cd
sudo apt update && \
sudo apt upgrade && \
conda update --all && \
conda clean --all	

# FrRsaFh:
