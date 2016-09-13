#smtp.py
import smtplib
def prompt(prompt):
    return input(prompt).strip()
fromaddr = prompt("From: ")
toaddrs  = prompt("To: ").split()
print("输入信息，^D (Unix) or ^Z (Windows)结束输入：")
# 添加From: 和 To: 头信息
msg = ("From: %s\r\nTo: %s\r\n\r\n"% (fromaddr, ", ".join(toaddrs)))
while True:
    try:
        line = input()
    except EOFError:
        break
    if not line:
        break
    msg = msg + line
print("信息长度为：", len(msg))
server = smtplib.SMTP('localhost')
server.set_debuglevel(1)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()
