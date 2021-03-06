#decorator4.py
import time, functools
def foo(f):
    """foo fucntion Docstring"""
    @functools.wraps(f)
    def wrapper(*x, **y):
        """wrapper fucntion Docstring"""
        print('调用函数：', f.__name__)
        return f(*x, **y)
    return wrapper
@foo
def bar(x):
    """bar fucntion Docstring"""
    return x**2
#测试代码
if __name__ == '__main__':
    print(bar(2))
    print(bar.__name__)
    print(bar.__doc__)
