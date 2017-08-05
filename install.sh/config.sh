# zsh
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
alias sync='rsync -e "ssh -p 5102" -rvz --exclude='miniconda3' ~/ guanhua@183.174.228.40:~/backup/home/'

# tmux
git clone https://github.com/gpakosz/.tmux.git
ln -s -f .tmux/.tmux.conf
cp .tmux/.tmux.conf.local ~
# 还需要进一步设置

# 配置 python
mkdir ~/.pip
touch ~/.pip/pip.conf
echo "[global]" >> ~/.pip/pip.conf
echo "index-url = https://pypi.tuna.tsinghua.edu.cn/simple" >> ~/.pip/pip.conf

# 配置 miniconda
wget -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-4.3.21-Linux-x86_64.sh
bash Miniconda3-4.3.21-Linux-x86_64.sh # 需要输入

# 配置 conda
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --set show_channel_urls yes

# 安装深度学习的必要软件
conda install tensorflow
pip install keras autopep8 cheat mycli ici unidecode pillow

# 配置 vimrc
mkdir  ~/.vim
scp -rP 5102 guanhua@183.174.228.40:~/.vim/vimrc ~/.vim/vimrc
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

# 配置youcompleteme
cd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer

# 配置 spacemacs，安装字体
echo "installing fonts at $PWD to ~/.fonts/"
mkdir -p ~/.fonts/adobe-fonts/source-code-pro
git clone https://github.com/adobe-fonts/source-code-pro.git ~/.fonts/adobe-fonts/source-code-pro
# find ~/.fonts/ -iname '*.ttf' -exec echo \{\} \;
fc-cache -f -v ~/.fonts/adobe-fonts/source-code-pro
echo "finished installing"

# 复制基础目录
scp -rp 5102 guanhua@183.174.228.40:~/workspace ~/workspace
