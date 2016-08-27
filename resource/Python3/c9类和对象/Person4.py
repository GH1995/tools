# Person4.py
class Person4:
    def say_hi(self, name):
        self.name = name
        print('您好，我叫', self.name)

p4 = Person4()
p4.say_hi('Alice')