# ��װ�������

## USTC resource
sudo sed -i 's/archive.ubuntu.com/mirrors.ustc.edu.cn/g' /etc/apt/sources.list && sudo apt update -y && sudo apt install curl -y
if [ $? -eq 0]
then
    echo "install USTC resource success!" >> install_log.txt;
else
    echo "install USTC resource failed!" >> install_log.txt;
fi

# essential
sudo apt-get install build-essential cmake
if [ $? -eq 0]
then
    echo "install essential success!" >> install_log.txt;
else
    echo "install essential failed!" >> install_log.txt;
fi

# python
sudo apt-get install python-dev python3-dev python-pip
(mkdir ~/.pip && touch ~/.pip/pip.conf)
echo '[global]' >> ~/.pip/pip.conf && echo 'index-url=http://pypi.douban.com/simple' >> ~/.pip/pip.conf
echo '[install]' >> ~/.pip/pip.conf && echo 'trusted-host = pypi.douban.com' >> ~/.pip/pip.conf
if [ $? -eq 0]
then
    echo "install python success!" >> install_log.txt;
else
    echo "install python failed!" >> install_log.txt;
fi

# git
sudo apt install git -y
if [ $? -eq 0]
then
    echo "install git success!" >> install_log.txt;
else
    echo "install git failed!" >> install_log.txt;
fi


# zsh
sudo apt install bash wget wget -y && sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)" &
if [ $? -eq 0]
then
    echo "install oh-my-zsh success!" >> install_log.txt;
else
    echo "install oh-my-zsh failed!" >> install_log.txt;
fi

# ��װ Vim �� Emacs
sudo apt install vim-gnome ctags -y && touch ~/.vimrc
if [ $? -eq 0]
then
    echo "install Vim success!" >> install_log.txt;
else
    echo "install Vim failed!" >> install_log.txt;
fi

sudo apt install emacs -y
if [ $? -eq 0]
then
    echo "install Emacs success!" >> install_log.txt;
else
    echo "install Emacs failed!" >> install_log.txt;
fi

# ��װVundle
# Vundle is short for Vim bundle and is a Vim plugin manager.
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
if [ $? -eq 0]
then
    echo "install Vundle success!" >> install_log.txt;
else
    echo "install Vundle failed!" >> install_log.txt;
fi

# ��װ������
sudo apt install clang g++ openjdk-8-jdk -y
if [ $? -eq 0]
then
    echo "install g++, clang, openjdk-8-jdk success!" >> install_log.txt;
else
    echo "install g++, clang, openjdk-8-jdk failed!" >> install_log.txt;
fi

# ��װ���ع���
sudo apt install axel aria2 -y
if [ $? -eq 0]
then
    echo "install aria2 and axel success!" >> install_log.txt;
else
    echo "install aria2 and axel failed!" >> install_log.txt;
fi

# ��װ�������ع���
# sudo apt install aria2c
# aria2c -s[�߳���] 10 -x[���ʹ�ü����߳�����] 10 -j[ͬʱ���ض����ļ�] 10
# echo "install aria2c success!" >> install_log.txt;

# ��װ��������
sudo apt install htop tree lynx -y
if [ $? -eq 0]
then
    echo "install tree, lynx and htop success!" >> install_log.txt;
else
    echo "install tree, lynx and htop failed!" >> install_log.txt;
fi


# ��װ screen
sudo apt install screen -y
# alt�ӷ�����������ն˸�֮��ת��
# -dmS �����Ự C+A+D�뿪 -r �ָ� -l �б�
if [ $? -eq 0]
then
    echo "install screen success!" >> install_log.txt;
else
    echo "install screen failed!" >> install_log.txt;
fi



# ��װopenssh-server openssh-client
sudo apt install openssh-server openssh-client -y
# ֹͣ����sudo /etc/init.d/ssh stop
# ��������sudo /etc/init.d/ssh start
# ��������sudo /etc/init.d/sshresart
# �Ͽ����ӣ�exit
# ��¼��ssh [-l login_name] [-p port] [user@]hostname
if [ $? -eq 0]
then
    echo "install openssh-server and openssh-server success!" >> install_log.txt;
else
    echo "install openssh-server and openssh-server failed!" >> install_log.txt;
fi


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
if [ $? -eq 0]
then
    echo "install MySQL success!" >> install_log.txt;
else
    echo "install MySQL failed!" >> install_log.txt;
fi
