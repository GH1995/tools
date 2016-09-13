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