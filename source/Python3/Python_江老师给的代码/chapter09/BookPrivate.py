#BookPrivate.py
class Book:                     #定义类Book
    def __init__(self, name, author, price):
        self.name = name
        self.author = author
        self.price = price
    def __check_name(self):       #定义私有方法
        if self.name == '' : return False
        else: return True
    def get_name(self):
        if self.__check_name(): print(self.name,self.author) #调用私有方法
        else:print('No value')
b = Book('Python程序设计教程','江红',0.0)    #创建对象
b.get_name()               #调用对象的方法
b.__check_name()           #直接调用私有方法，非法
