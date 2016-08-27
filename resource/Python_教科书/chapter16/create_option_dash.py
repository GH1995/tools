#create_option_dash.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70);c.pack()#创建并显示Canvas
c.create_rectangle(10,10,60,60,dash=(4,2)) #虚线为4个像素点紧跟2个像素空格
c.create_rectangle(70,10,120,60,dash=(4,)) #虚线为4个像素点紧跟4个像素空格
#虚线为4个像素点跟4个像素空格紧跟2个像素点紧跟2个像素空格
c.create_rectangle(130,10,180,60,dash=(4,2,2,4)) 
#虚线为2个像素点紧跟2个像素空格跟4个像素点紧跟4个像素空格
c.create_rectangle(190,10,240,60,dash=(4,2,2,4),dashoffset=2)
