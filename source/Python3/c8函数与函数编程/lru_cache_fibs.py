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