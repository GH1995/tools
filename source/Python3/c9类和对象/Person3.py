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