#grid2.py
from tkinter import * #导入tkinter模块所有内容
root = Tk() 
Button(root, text="1").grid(row=0, column=0) #按钮1放置第0行第0列
Button(root, text="2").grid(row=0, column=1) #按钮2放置第0行第1列
Button(root, text="3").grid(row=0, column=2) #按钮3放置第0行第2列
Button(root, text="4").grid(row=1, column=0) #按钮4放置第1行第0列
Button(root, text="5").grid(row=1, column=1) #按钮5放置第1行第1列
Button(root, text="6").grid(row=1, column=2) #按钮6放置第1行第2列
Button(root, text="7").grid(row=2, column=0) #按钮7放置第2行第0列
Button(root, text="8").grid(row=2, column=1) #按钮8放置第2行第1列
Button(root, text="9").grid(row=2, column=2) #按钮9放置第2行第2列
Button(root, text="0").grid(row=3, column=0, columnspan=2, sticky=E+W) #跨2列，左右贴紧
Button(root, text=".").grid(row=3, column=2, sticky=E+W) #左右贴紧
root.mainloop()
