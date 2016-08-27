#create_option_stipple.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=300, height=70);c.pack()#创建并显示Canvas
#按指定填充画刷绘制各类红色填充矩形
c.create_rectangle(10,10,60,60,fill='red',stipple='gray12') 
c.create_rectangle(70,10,120,60,fill='red',stipple='gray12',offset= NE)
c.create_rectangle(150,10,200,60,fill='red',outline='blue',width=20,outlinestipple='error')
c.create_rectangle(230,10,280,60,fill='red',outline='blue',width=20,outlinestipple='error',offset= NE)
