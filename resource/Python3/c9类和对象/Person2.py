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