#decorator2.py
import time, functools
def timeit(func):
    def wrapper(*s):
        start = time.perf_counter()
        func(*s)
        end = time.perf_counter()
        print('运行时间:', end - start)
    return wrapper
@timeit
def my_sum(n):
    sum = 0
    for i in range(n): sum += i
    print(sum)
#测试代码
if __name__ == '__main__':
    my_sum(100000)
