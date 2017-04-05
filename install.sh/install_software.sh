# ��װ�������

## USTC resource
sudo sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list && sudo apt update -y && sudo apt install curl -y

# essential
sudo apt-get install build-essential cmake

# python
sudo apt-get install python-dev python3-dev python-pip
(mkdir ~/.pip && touch ~/.pip/pip.conf)
echo '[global]' >> ~/.pip/pip.conf
echo 'index-url=http://pypi.douban.com/simple' >> ~/.pip/pip.conf
echo '[install]' >> ~/.pip/pip.conf
echo 'trusted-host = pypi.douban.com' >> ~/.pip/pip.conf

# git
sudo apt install git -y

# zsh
sudo apt install bash wget wget -y && sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)" &

# ��װ Vim �� Emacs
sudo apt install vim-gnome ctags -y && touch ~/.vimrc
sudo apt install emacs -y

# ��װVundle
# Vundle is short for Vim bundle and is a Vim plugin manager.
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

# ��װ������
sudo apt install clang g++ openjdk-8-jdk -y

# ��װ���ع���
sudo apt install axel aria2 -y
# axel -n 10

# ��װ�������ع���
# sudo apt install aria2c
# aria2c -s[�߳���] 10 -x[���ʹ�ü����߳�����] 10 -j[ͬʱ���ض����ļ�] 10
# echo "install aria2c success!" >> install_log.txt;

# ��װ��������
sudo apt install htop tree lynx -y

# ��װ screen
sudo apt install screen -y
# alt�ӷ�����������ն˸�֮��ת��
# -dmS �����Ự C+A+D�뿪 -r �ָ� -l �б�

# ��װopenssh-server openssh-client
sudo apt install openssh-server openssh-client -y
# ֹͣ����sudo /etc/init.d/ssh stop
# ��������sudo /etc/init.d/ssh start
# ��������sudo /etc/init.d/sshresart
# �Ͽ����ӣ�exit
# ��¼��ssh [-l login_name] [-p port] [user@]hostname

# ��װMySQL
sudo apt install mysql-server mysql-client
# mysql -uroot -p 		��¼
# sudo start mysql 		����MySQL����
# sudo stop mysql 		ֹͣMySQL����
# sudo mysqladmin -u root password newpassword �޸� MySQL �Ĺ���Ա����
# ���ݿ���Ŀ¼��		/var/lib/mysql/
# ��������ļ����Ŀ¼��/usr/share/mysql
# ���������Ŀ¼�� /usr/bin(mysqladmin mysqldump������)
# �����Ų����Ŀ¼�� /etc/rc.d/init.d/
