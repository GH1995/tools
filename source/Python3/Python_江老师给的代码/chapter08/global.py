#global.py
pi = 3.141592653589793 #全局变量
e = 2.718281828459045 #全局变量
def my_func():
    global pi #全局变量，与前面的全局变量pi指向相同的对象
    pi = 3.14
    print('global pi =', pi)
    e = 2.718 #局部变量，与前面的全局变量e指向不同的对象
    print('local e =', e)
print('module pi =', pi)
print('module e =', e)
my_func()
print('module pi =', pi)
print('module e =', e)
