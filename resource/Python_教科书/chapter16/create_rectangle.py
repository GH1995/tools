#create_rectangle.py
from tkinter import *
root = Tk()
c = Canvas(root,bg = 'white', width=130, height=70) 
c.pack()
c.create_rectangle(10,10,60,60,fill='red')
c.create_rectangle(70,10,120,60,fill='red',outline='blue',width=5) 
