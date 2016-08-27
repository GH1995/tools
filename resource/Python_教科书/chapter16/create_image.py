#create_image.py
from tkinter import * 
root = Tk()
c = Canvas(root,bg = 'white', width=100, height=140); c.pack() #创建并显示Canvas
logo = BitmapImage(file=r'C:\Python\images\xbm\face.xbm')  #图像文件
c.create_image(50,70, image=logo)                       #绘制图像
