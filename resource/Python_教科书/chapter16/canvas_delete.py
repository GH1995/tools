#canvas_delete.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=250, height=70); c.pack()  #创建并显示Canvas组件
c.create_rectangle(10,10,60,60,fill='red',tags='red')  #红色填充矩形
c.create_rectangle(70,10,120,60)                #矩形
c.create_rectangle(130,10,180,60,fill='red',tags='red') #红色填充矩形
c.create_rectangle(190,10,240,60)               #矩形
for i in c.find_withtag('red'):      #查找带标签'red'的绘制对象
    c.delete(i)                 #删除绘制对象

