#create_option_arrow.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=200, height=70); c.pack()#创建并显示Canvas
c.create_line(10,10,60,60,fill='red')  #绘制红线
c.create_line(70,10,120,60,arrow=LAST) #绘制结束端带箭头的线
c.create_line(130,10,180,60,arrow=BOTH,arrowshape=(3,5,4)) #绘制两端带箭头的线
