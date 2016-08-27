# 函数与函数编程

# 函数的声明与调用

# reference:my_add.py
def my_add(a, b):
    return a + b

def my_print(msg):
    print(msg)

c = my_add(11, 22)
my_print(c)

# 参数的传递

# 形式参数与实际参数

# reference:my_max1.py
def my_max1(a, b):
    if a > b:
        print(a, '>', b)
    elif a == b:
        print(a, '=', b)
    else:
        print(a, '<', b)

my_max1(1, 2)
x = 11; y = 8
my_max1(x, y)


# 可选参数
# reference:my_sum1.py
def my_sum1(mid_score, end_score, mid_rate = 0.4):
    score = mid_score * mid_rate + end_score * (1 - mid_rate)
    print(format(score, '.2f'))

my_sum1(88, 79)
my_sum1(88, 79, 0.5)


# 位置参数和命名参数

# reference:my_sum2.py
def my_sum2(mid_score, end_score, mid_rate = 0.4):
    score = mid_score*mid_rate + end_score*(1 - mid_rate)
    print(format(score, '.2f'))

my_sum2(88, 79)
my_sum2(mid_score=88, end_score=79)
my_sum2(end_score=79,mid_score=88)


# 可变参数(VarArgs)

# *param    元组
# **param   字典

# my_sumVarArgs1.py
def my_sum3(a, b, *c):
    total = a + b
    for n in c:
        total += n
    return total

print(my_sum3(1, 2))
print(my_sum3(1, 2, 3, 4, 5))
print(my_sum3(1, 2, 3, 4, 5, 6, 7))

# my_sumVarArgs2.py
def my_sum4(a, b, *c, **d):
    total = a + b
    for n in c:
        total += n
    for key in d:
        total += d[key]

    return total

print(my_sum4(1, 2))
print(my_sum4(1, 2, 3, 4, 5))
print(my_sum4(1, 2, 3, 4, 5, male = 6, female = 7))

# 强制命名参数Keyword_only
# reference:my_sum5.py
def my_sum(*, mid_score, end_score, mid_rate = 0.4):
    score = mid_score*mid_rate + end_score*(1 - mid_rate)
    print(format(score, '.2f'))

my_sum(mid_score=88, end_score=79)
my_sum(end_score=79, mid_score=88)

# 函数的返回值
# my_maxReturn.py
def my_max(a, b, *c):
    max_value = a
    if max_value < b:
        max_value = b
    for n in c:
        if max_value < n:
            max_value = n
    return max_value

print(my_max(1, 2))
print(my_max(1, 7, 11, 2, 5))


# 全局语句global

# global.py
pi = 3.1415
e = 2.71828
def my_func():
    global pi
    pi = 3.14
    print('globa pi = ', pi)
    e = 2.71
    print('local e = ', e)

print('module pi = ', pi)
print('module e = ', e)
my_func()
print('module pi = ', pi)
print('module e = ', e)

# 非局部语句nonlocal
# nonlocal.py
def outer_func():
    tax_rate = 0.17
    print('outfucnc tax rate = ', tax_rate)

    def inner_func():
        nonlocal tax_rate
        tax_rate = 0.05
        print('outfucnc tax rate = ', tax_rate)
    inner_func()
    print('outfucnc tax rate = ', tax_rate)

outer_func()

# 函数装饰器Decorators
# @装饰器
# def 函数1:
#   函数体
#
# 函数1 = 装饰器1（函数1）
# 装饰器实际上就是一个函数，一个用来包装函数的函数。装饰器返回一个修改之后的函数对象，且具有相同的函数签名。
# 装饰器是一种设计模式，其作用是为已经存在的函数的函数添加额外的功能，插入日志、性能测试、事物处理等。

# decorator.py
def foo(f):
    """foo function Docstring"""
    def wrapper(*x, **y):
        """wrapper function Docstring"""
        print('调用函数：', f.__name__)
        return f(*x, **y)

    return wrapper

@foo
def bar(x):
    """bar function Docstring"""
    return x**2

if __name__ == '__main__':
    print(bar(2))
    print(bar.__name__)
    print(bar.__doc__)

# decorator2.py
import time, functools
def timeit(func):
    def wrapper(*s):
        start = time.perf_counter()
        func(*s)
        end = time.perf_counter()
        print('running time:', end - start)
    return wrapper

@timeit
def my_sum(n):
    sum = 0
    for i in range(n):
        sum += i
    print(sum)

# 测试
if __name__ == '__main__':
    my_sum(100000)

# decorator3.py
def makebold(fn):
    def wrapper(*s):
        return "<b>" + fn(*s) + "</b>"
    return wrapper

def makeitalic(fn):
    def wrapper(*s):
        return "<i>" + fn(*s) + "</i>"
    return wrapper

@makebold
@makeitalic
def htmltags(str1):
    return str1

# 测试代码
print(htmltags('Hello'))





# @functools.wraps装饰器
# 函数被壮士后，其特殊属性(__name__, __doc__等)将变成相应装饰器函数的特殊属性内容，故使用反射时，可能会导致意外的结果。
# functools模块的wraps装饰器用于解决上述问题，可以保留特殊属性。

# decorator4.py
import time, functools
def foo(f):
    """foo function Docstring"""
    @functools.wraps(f)
    def wrapper(*x, **y):
        """wrapper function Docstring"""
        print('调用函数：', f.__name__)
        return f(*x, **y)
    return wrapper

@foo
def bar(x):
    """bar function Docstring"""
    return x**2

# testing code
if __name__ == '__main__':
    print(bar(2))
    print(bar.__name__)
    print(bar.__doc__)


# functools.update_wrapper函数，使用指定的特殊属性

# update_wrapper.py
import time, functools
def foo(f):
    """foo function Docstring"""
    def wrapper(*x, **y):
        """wrapper function Docstring"""
        print('调用函数：', f.__name__)
        return f(*x, **y)
    return functools.update_wrapper(wrapper, f)

@foo
def bar(x):
    """bar function Docstring"""
    return x**2

# testing code
if __name__ == '__main__':
    print(bar(2))
    print(bar.__name__)
    print(bar.__doc__)






# 递归函数
import sys
sys.getrecursionlimit()     # 获取最大递归次数
sys.getrecursionlimit(100)  # 设置最大递归次数

# factorial.py
def factorial(num):
    if num == 0:
        return 1
    else:
        return num*factorial(num - 1)

# testing code
for i in range(10):
    print(factorial(i), end = ' ')


# 作为对象的函数
def compute(f, s):
    return f(s)


# Lambda表达式和匿名函数
# 在同一行中定义函数，生成匿名函数
f = lambda x, y:x+y
i = map(lambda x:x*3, (1, 2, 3))
for t in i:print(t, end = ' ')


# operator模块和运算符函数
import operator
dir(operator)
operator.add(13, 23)
func = lambda f, x, y:f(x, y)
func(operator.add, 12, 34)


# eval、exec和compile函数
globals()   # 全局变量，字典映射表
locals()    # 局部变量，字典映射表
vars()      # locals()
vars(str)   # 返回指定对象的字典列表

# eval函数和动态表达式的求值
# eval的功能是将字符串生成语句执行，如果存在不安全语句
# 一般用于动态表达式求值，返回
x = 2
str_function = input("请输入表达式：")
>>> x**2 + 2*x + 11
eval(str_function)


# exec函数和动态语句的执行
# 用于动态表达式执行
exec("for i in range(10):print(i, end = ' ')")

# compile函数和动态语句的执行
# compile编译代码为代码对象
co = compile("for i in range(10):print(i, end = ' ')", '', 'exec')
exec(co)

# functools模块和函数工具

# partial对象
# 设置预先已知的参数，减少传递参数的个数
import functools, math
pow2 = functools.partial(math.pow, 2)
for i in range(11):
    print(format(pow2(i), '0.0f'), end = ' ')

# reduce函数
# 使用带两个参数的函数func，对一个数据集合迭代操作
import functools, operator
functools.reduce(operator.add, [1, 2, 3, 4, 5, 6], [10])


# @functools.lru_cache装饰器
# 缓存maxsize个函数调用结果

# lru_cache_fibs.py
import functools
@functools.lru_cache(maxsize=None)

def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

# test code
if __name__ == '__main__':
    for i in range(16):
        print(fib(i), end= ' ')
        print('\n', fib.cache_info())


























