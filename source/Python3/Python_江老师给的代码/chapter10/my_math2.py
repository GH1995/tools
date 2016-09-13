#my_math2.py
PI = 3.14 
def add(x, y):
    return x + y
def sub(x, y):
    return x - y
def mul(x, y):
    return x * y
def div(x, y):
    return x / y
#测试代码
def main():
    print('123 + 446 =', add(123, 456))
    print('123 - 446 =', sub(123, 456))
    print('123 * 446 =', mul(123, 456))
    print('123 / 446 =', div(123, 456))
if __name__ == '__main__': #如果独立运行时，侧运行测试代码
    main()
