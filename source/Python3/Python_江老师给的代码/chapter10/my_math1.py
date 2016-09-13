#my_math1.py
PI = 3.14    #定义变量
def add(x, y): #定义函数
    return x + y  #加
def sub(x, y):
    return x - y  #减
def mul(x, y):
    return x * y  #乘
def div(x, y):
    return x / y  #除
#测试代码
if __name__ == '__main__': #如果独立运行时，则运行测试代码
    print('123 + 446 =', add(123, 456))
    print('123 - 446 =', sub(123, 456))
    print('123 * 446 =', mul(123, 456))
    print('123 / 446 =', div(123, 456))

