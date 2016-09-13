# PersonInit.py
class Person5:
    def __init__(self, name):
        self.name = name
    def say_hi(self):
        print('您好，我叫', self.name)

p5 = Person5('Helen')
p5.say_hi()