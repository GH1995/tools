# -*- coding: utf-8 -*-
import datetime
sName = input("请输入您的姓名：")
birthyear = int(input("请输入您的输出年份："))
age = datetime.date.today().year - birthyear
print("您好！{0}。您{1}岁。".format(sName, age))