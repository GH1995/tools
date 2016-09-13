#create_bitmap.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=200, height=40); c.pack() #创建并显示Canvas
c.create_bitmap(30,20, bitmap='error')    #error图标
c.create_bitmap(70,20, bitmap='hourglass') #沙漏图标
c.create_bitmap(130,20, bitmap='info')    #信息图标
c.create_bitmap(190,20, bitmap='warning') #警告图标
