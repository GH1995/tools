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