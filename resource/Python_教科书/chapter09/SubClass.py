#SubClass.py
class Dimension:  #定义类Dimensions
    def __init__(self, x, y): #构造函数
        self.x = x  #x坐标
        self.y = y  #y坐标
    def area(self): #覆盖基类的方法area()
        pass
class Circle(Dimension):  #定义类Circle
    def __init__(self, r): #构造函数
        Dimension.__init__(self, r, 0)
    def area(self):      #圆面积
        return 3.14 * self.x * self.x
class Rectangle(Dimension):  #定义类Circle
    def __init__(self, w, h): #构造函数
        Dimension.__init__(self, w, h)
    def area(self):  #覆盖基类的方法area()
        return self.x * self.y  #矩形面积
d1 = Circle(2.0)          #创建对象：圆
d2 = Rectangle(2.0, 4.0)   #创建对象：矩形
print(d1.area(), d2.area())  #打印面积
