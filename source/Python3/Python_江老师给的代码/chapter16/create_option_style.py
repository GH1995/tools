#create_option_style.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70); c.pack() #创建并显示Canvas 
#按顶点连接样式画线
c.create_line(10,10,60,10,10,60,60,60,width=10,joinstyle=ROUND)
c.create_line(70,10,120,10,70,60,120,60,width=10,joinstyle=BEVEL)
c.create_line(130,10,180,10,130,60,180,60,width=10,joinstyle=MITER)
c.create_line(190,10,240,10,190,60,240,60,width=10,smooth=1,splinesteps=30)
