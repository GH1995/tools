#create_window.py
from tkinter import *
def f1():
    print('You click me!')
root = Tk()
c = Canvas(root,bg = 'white', width=100, height=40); c.pack() #创建并显示Canvas
button1 = Button(c,text = 'ClickMe',command = f1) #ClickMe按钮
c.create_window(30,20, window=button1, anchor=W) #创建组件
root.mainloop()
