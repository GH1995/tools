class Person1:
    pass

p1= Person1()
print(p1)

# 实例属性

# Person2.py
class Person2:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def say_hi(self):
        print('您好，我叫', self.name)

p1 = Person2('张三', 25)
p1.say_hi()
print(p1.age)

# 类属性

# Person3
class Person3:
    count = 0

    def __init__(self, name, age):
        self.name = name
        self.age = age
        Person3.count += 1
    def __del__(self):
        Person3.count -= 1
    def say_hi(self):
        print('您好，我叫', self.name)
    def get_count():
        print('总计数为：', Person3.count)

print('总计数为：', Person3.count)

p31 = Person3('张三', 25)
p31.say_hi()
Person3.get_count()

p32 = Person3('李四', 28)
p32.say_hi()
Person3.get_count()

del p31
Person3.get_count()

del p32
Person3.get_count()

# 私有属性
# 约定以两个下划线开头，但是不以两个下划线结束的属性是private，其他为public
class A:
    __name = 'Class A'

    def get_name():
        print(A.__name)
A.get_name()


# @property装饰器

# property.py
class Person11:
    def __init__(self, name):
        self.__name = name

    @property
    def name(self):
        """I'm the 'x' property."""
        return self.__name

# testing code
if __name__ == '__main__':
    p = Person11('王五')
    print(p.name)

# property2.py
class Person12:
    def __init__(self, name):
        self.__name = name

    @property
    def name(self):
        """I'm the 'x' property."""
        return self.__name

    @name.setter
    def name(self, value):
        self.__name = value

    @name.deleter
    def name(self):
        del self.__name

# testing code
if __name__ == '__main__':
    p = Person12('A')
    p.name = 'B'
    print(p.name)

# property3.py
class Person13:
    def __init__(self, name):
        self.__name = name

    def getname(self):
        return self.__name

    def setname(self, value):
        self.__name = value

    def delname(self):
        del self.__name

    name = property(getname, setname, delname, "I'm the 'name' property.")

# testing code
if __name__ == '__main__':
    p = Person13('爱丽丝')
    print(p.name)
    p.name = 'robert'
    print(p.name)

# 特殊属性special attributes

# 自定义属性
class C1:
    pass

o = C1()
o.name = "custom name"
#o.name
#o.__dict__


# custom_attribute.py
class CustomAttribute(object):
    def __init__(self):
        pass
    def __getattribute__(self, name):
        return str.upper(object.__getattribute__(self, name))
    def __setattr__(self, name, value):
        object.__setattr__(self, name, str.strip(value))

# testing code
if __name__ == '__main__':
    o = CustomAttribute()
    o.firstname = '    mary'
    print(o.firstname)

# 方法
# 方法的声明和调用

# Person4.py
class Person4:
    def say_hi(self, name):
        self.name = name
        print('您好，我叫', self.name)

p4 = Person4()
p4.say_hi('Alice')

# __init__方法(构造函数)和__new__方法

# PersonInit.py
class Person5:
    def __init__(self, name):
        self.name = name
    def say_hi(self):
        print('您好，我叫', self.name)

p5 = Person5('Helen')
p5.say_hi()

# PointInit.py
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

p1 = Point()
print("p1({0}, {1})".format(p1.x, p1.y))

p1 = Point(5, 5)
print("p1({0}, {1})".format(p1.x, p1.y))

# 实例方法

# 类方法
# @classmethod
# def classmethod(cls, [形参列表]):
#       函数体

# TemperatureConverter.py
class TemperatureConverter:
    @classmethod
    def c2f(cls, t_c):
        t_c = float(t_c)
        t_f = (t_c*9/5) + 32
        return t_f

    @classmethod
    def f2c(cls, t_f):
        t_f = float(t_f)
        t_c = (t_f - 32)*5/9
        return t_c

# testing code
if __name__ == '__main__':
    print('1.从摄氏温度到华氏温度.')
    print('2.从华氏温度到摄氏温度.')
    choice = int(input('请选择转换方向：'))

    if choice == 1:
        t_c = float(input('请输入摄氏温度：'))
        t_f = TemperatureConverter.c2f(t_c)
        print('华氏温度为：{0:.2f}'.format(t_f))

    if choice == 2:
        t_f = float(input('请输入华氏温度：'))
        t_c = TemperatureConverter.f2c(t_f)
        print('摄氏温度为：{0:.2f}'.format(t_c))

# 静态方法
# @staticmethod
# def 静态方法名([形参列表]):
#       函数体


# 私有方法

# BookPrivate.py
class Book:
    def __init__(self, name, author, price):
        self.name = name
        self.author = author
        self.price = price
    def __check_name(self):
        if self.name == ' ':
            return False
        else:
            return True
    def get_name(self):
        if self.__check_name():
            print(self.name, self.author)
        else:
            print('No value')

b = Book('Python程序设计教程', '江红', 1.0)
b.get_name()
# b.__check_name()


# 方法重载（基本没有必要，重名函数只有最后一个被使用）

# 运算符重载
# OpOverload.py
class MyList:
    def __init__(self, *args):
        self.__mylist = []
        for arg in args:
            self.__mylist.append(arg)

    def __add__(self, n):
        for i in range(0, len(self.__mylist)):
            self.__mylist[i] += n
    def __sub__(self, n):
        for i in range(0, len(self.__mylist)):
            self.__mylist[i] -= n
    def __mul__(self, n):
        for i in range(0, len(self.__mylist)):
            self.__mylist[i] *= n
    def __truediv__(self, n):
        for i in range(0, len(self.__mylist)):
            self.__mylist[i] /= n

    def __len__(self):
        return len(self.__mylist)
    def __repr__(self):
        str1 = ''
        for i in range(0, len(self.__mylist)):
            str1 += str(self.__mylist[i]) + ' '
        return str1
m = MyList(1, 2, 3, 4, 5)
m + 2;print(repr(m))
m - 1;print(repr(m))
m * 4;print(repr(m))
m / 2;print(repr(m))
print(len(m))

# @functools.total_ordeing装饰器
# 实现大部分重载运算符

# total_ordering_student.py
import functools
@functools.total_ordering
class Student:
    def __init__(self, firstname, lastname):
        self.firstname = firstname
        self.lastname = lastname
    def __eq__(self, other):
        return ((self.lastname.lower(), self.firstname.lower()) == (other.lastname.lower(), other.firstname.lower()))
    def __lt__(self, other):
        return ((self.lastname.lower(), self.firstname.lower()) < (other.lastname.lower(), other.firstname.lower()))

# testing code
if __name__ == '__main__':
    s1 = Student('Mary', 'Clinton')
    s2 = Student('Mary', 'Clinton')
    s3 = Student('Charlie', 'Clinton')

    print(s1 == s2)
    print(s1 > s3)

# 特殊方法special method

# __call__方法和可调用对象（callabe）

# CallabeObj.py
class GDistance:
    def __init__(self, g):
        self.g = g
    def __call__(self, t):
        return (self.g * t**2)/2

# testing code
if __name__ == '__main__':
    e_gdist = GDistance(9.8)
    for t in range(11):
        print(format(e_gdist(t), "0.2f"), end='')

# DerivedClass.py
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def say_hi(self):
        print('您好，我叫{0}，{1}岁'.format(self.name, self.age))

class Student(Person):
    def __init__(self, name, age, stu_id):
        Person.__init__(self, name, age)
        self.stu_id = stu_id
    def say_hi(self):
        Person.say_hi(self)
        print('我是学生，我的学号为：', self.stu_id)

p1 = Person('A', 33)
p1.say_hi()
s1 = Student('B', 20, '2000000000')
s1.say_hi()


# 类成员的继承和重写

# SubClass.py
class Dimension:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def area(self):
        pass

class Circle(Dimension):
    def __init__(self, r):
        Dimension.__init__(self, r, 0)
    def area(self):
        return 3.14*self.x*self.x

class Rectangle(Dimension):
    def __init__(self, w, h):
        Dimension.__init__(self, w, h)
    def area(self):
        return self.x*self.y


d1 = Circle(2.0)
d2 = Rectangle(2.0, 4.0)

print(d1.area(), d2.area())


# 对象的引用、浅拷贝和深拷贝

# 对象的浅拷贝
# - 切片操作    acc11[:]
# -对象实例化    list(acc1)
# copy模块的copy函数     copy.copy(acc1)

# 浅拷贝，对象中包含的子对象并不拷贝，而是引用同一个子对象


# 深拷贝
# copy模块的deepcopy函数
import copy
acc1 = ['Chaelie', ['credit', 0.0]]
acc5 = copy.deepcopy(acc1)
acc5[0] = 'Clinton'
acc5[1][1] = -19.9
























