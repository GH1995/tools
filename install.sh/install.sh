sudo mv /etc/apt/sources.list /etc/apt/sources.list.bak
sudo apt update

# esstenial software, such as, zsh tmux
sudo apt-get install build-essential cmake vim python-dev python3-dev zsh git tmux autojump emacs ctags g++ clang aria2 axel openssh-server openssh-client mysql-server mysql-client texlive-full fontforge latex-cjk-chinese pandoc python-autopep8 dot2tex

# 卸载软件
sudo apt purge xul-ext-ubufox rhythmbox
sudo apt purge libreoffice-core
sudo apt purge libreoffice-*
sudo apt purge unity-webapps-*
sudo apt-get purge thunderbird
sudo apt purge aisleriot transmission-common
sudo apt purge libreoffice-common
sudo apt purge unity-webapps-common
sudo apt purge thunderbird totem rhythmbox empathy brasero simple-scan gnome-mahjongg aisleriot gnome-mines cheese gnome-sudoku transmission-common gnome-orca webbrowser-app landscape-client-ui-install  deja-dup empathy-common  gwibber gcalctool  gnome-power-manager  ubuntuone  bluez simple-scan hplip* printer-driver*  gedit mahjongg  gnome-sudoku gnomine wodim imagemagick*

# 收尾工作
sudo apt upgrade
sudo apt autoclean
sudo apt autoremove
conda update conda
conda update --all
