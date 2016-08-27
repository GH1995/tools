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