import getpass
def checkpass(usr, passwd):
    if usr == 'GH' and passwd == 'passwd':
        return True
    else:
        return False
    
if __name__ == '__main__':
    user = input('用户名：')
    passwd = getpass.getpass('密码：')
    if checkpass(user, passwd):
        print("登录成功")
    else:
        print("登录失败")