#property2.py
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
#测试代码
if __name__ == '__main__':
    p = Person12('姚六')
    print(p.name)
    p.name = '王依依'
    print(p.name)
