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