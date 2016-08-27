#raise_exception.py
from NumberError import *
def average(data):
    sum = 0
    for i in data:
        if i < 0: raise NumberError(str(i))
        sum += i
    return sum/len(data)
if __name__=='__main__':
    data1 = (44, 78, 90, 80, 55)
    print('平均值=', average(data1))
    data2 = (44, 78, 90, -80, 55)
    print('平均值=', average(data2))
