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