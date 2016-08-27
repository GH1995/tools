#register.py
import tkinter as tk        #导入tkinter模块
class Application(tk.Frame): #定义GUI应用程序类，派生于Frame类
    def __init__(self, master=None): #构造函数，master为父窗口
        tk.Frame.__init__(self, master) #调用父类的构造函数
        self.grid() #调用组件的pack方法，调整其显示位置和大小
        self.createWidgets()  #调用对象方法，创建子组件
    def createWidgets(self):   #对象方法：创建子组件
        self.lblEmail = tk.Label(self, text='用户名')   #创建Label组件-用户名
        self.lblPass1 = tk.Label(self, text='密码')    #创建Label组件-密码
        self.lblPass2 = tk.Label(self, text='确认密码') #创建Label组件-确认密码
        self.lblDesc = tk.Label(self, text='自我简介') #创建Label组件-自我简介
        self.lblEmail.grid(row=0, column=0, sticky=tk.E) #Email标签放置第0行第0列
        self.lblPass1.grid(row=1, column=0, sticky=tk.E) #密码标签放置第1行第0列
        self.lblPass2.grid(row=2, column=0, sticky=tk.E) #确认密码标签放置第2行第0列
        self.lblDesc.grid(row=3, column=0, sticky=tk.NE) #自我简介标签放置第3行第0列
        self.entryEmail = tk.Entry(self)          #创建Entry组件
        self.entryPass1 = tk.Entry(self, show='*')  #密码显示为*
        self.entryPass2 = tk.Entry(self, show='*')  #确认密码显示为*
        self.textDesc = tk.Text(self, width=20, height=5) #创建Text组件
        self.entryEmail.grid(row=0, column=1, columnspan=2) #用户名文本框放置第0行第1列
        self.entryPass1.grid(row=1, column=1, columnspan=2) #密码文本框放置第1行第1列
        self.entryPass2.grid(row=2, column=1, columnspan=2) #确认密码文本框放置第2行第1列
        self.textDesc.grid(row=3, column=1, columnspan=2) #自我简介文本框放置第3行第1列
        self.btnOk = tk.Button(self, text='注册', command=self.funcOK) #创建按钮组件
        self.btnOk.grid(row=4, column=1, sticky=tk.E) #注册按钮放置第4行第1列
        self.btnCancel = tk.Button(self, text='取消', command=root.destroy) #创建按钮组件
        self.btnCancel.grid(row=4, column=2, sticky=tk.W) #取消按钮放置第4行第2列
    def funcOK(self): #定义注册事件处理程序
        str1 = '欢迎注册：\n'
        str1 += "您的帐户为：" + self.entryEmail.get() + '\n'
        str1 += "您的特长为：\n" + self.textDesc.get(0.0, tk.END)
        tk.messagebox.showinfo("注册", str1) #弹出消息框
root = tk.Tk() #创建1个Tk根窗口组件root
root.title('新用户注册') #设置窗口标题
app = Application(master=root) #创建Application的对象实例
app.mainloop() #调用组件的mainloop方法，进入事件循环
