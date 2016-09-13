# 第11章 迭代器和生成器

# 11.1 迭代对象、迭代器和可迭代协议

# 可迭代对象
# collections.abc模块中抽象基类Iterable
# 实现了__iter__方法的对象是可迭代对象，返回一个迭代器(iterator)

# 使用内置的iter(obj)函数可以返回一个迭代器(iterator)
import collections.abc
isinstance((1, 2, 3), collections.abc.Iterable)
isinstance('python', collections.abc.Iterable)

# 迭代器
# 实现了__next__()的对象是迭代器。调用__next__()方法依次返回下一个项目值，如果没有就返回StopIteration
import collections.abc
i1 = (i*2*2 for i in range(10))
isinstance(i1, collections.abc.Iterable)

# 迭代器协议
# __iter__()和__next__()

# 可迭代对象的迭代
t = (1, 2)
i = iter(t)
next(i)
next(i)
next(i)

# while.py
t = (1, 2, 3, 4 ,5, 6, 7 ,8, 9, 0)
fetch = iter(t)
while True:
    try:
        i = next(fetch)
    except StopIteration:
        break
        print(i, end=' ')

# 可迭代对象的迭代：for语句
for i in i1:print(i, end = ' ')


# 自定义可迭代对象和迭代器

# FibonacciIterNext.py
class Fib:
    def __init__(self):
        self.a, self.b = 0, 1
    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a
    def __iter__(self):
        return self

# testing code
fibs = Fib()
for f in fibs:
    if f < 10000:
        print(f, end = ',')
    else:
        break

# 生成器函数（generator）
# 使用yield语句代替return返回一个值

def gentripls(n):
    for i in range(n):
        yield i*3

f = gentripls(10)
i = iter(f)
next(i)
for  t in f:print(t, end=' ')

# FibonacciYield.py
def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield a

# tesing code
fibs = fib()
for f in fibs:
    if f < 1000:
        print(f, end = ' ')
    else:
        break

# 反向迭代器：reverse迭代器
# 如果一个可迭代对象实现了__reversed__()方法，则可以使用reverse()函数获得其反方向可迭代对象
reversed([1, 2, 3, 4, 5])
for i in reversed([1, 2, 3, 4, 5]):print(i, end=' ')

# reverseCountdown.py
class Countdown:
    def __init__(self, start):
        self.start = start

    # 正向迭代
    def __iter__(self):
        n = self.start
        while n > 0:
            yield n
            n -= 1

    # 反向迭代
    def __reversed__(self):
        n = 1
        while n <= self.start:
            yield n
            n += 1
# testing code
if __name__ == '__main__':
    for i in Countdown(10):print(i, end=' ')
    for i in reversed(Countdown(10)):print(i, end=' ')

# 生成器表达式

# 生成器表达式的语法和列表解析基本一样，只不过生成器表达式使用()代替[]。
for j in (i**2 for i in range(10)):print(j, end=' ')
for j in (i for i in range(10) if i%2 == 0):print(j, end=' ')


# Python内置的可迭代对象

# range可迭代对象
for i in range(1, 10):
    print(i, end=',')
list(range(1, 10, 2))

# map迭代器和itertools.starmap迭代器
list(map(abs, (1, -2, 3)))   # [1, 2, 3]
import operator
list(map(operator.add, (1, 2, 3), (1, 2, 3), (1, 2, 3)))

# 如果函数的参数为元组，则需要使用itertools.starmap迭代器
import itertools
list(itertools.starmap(pow, [(2, 5), (3, 2), (10, 3)]))     # [32, 9, 1000]

# filter迭代器和itertools.filterfalse迭代器
# filter使用知道函数处理可迭代对象的每个元素，函数返回bool类型的值。
# 若结果为True，则返回该元素；
# 若function为None，则返回为True的元素。

filter;
list(filter(lambda x:x > 0, (-1, 2, -3, 0, 5)))
list(filter(None, (1, 2, 3, 0, 5)))

# filterfalse根据条件函数predicate处理可迭代对象的每个元素
# 若结果为True，则丢弃，否则返回该元素
import itertools
list(itertools.filterfalse(lambda x:x%2, range(10)))    # [0, 2, 4, 6, 8]

# zip迭代器和zip_longest迭代器
# zip拼接多个可迭代对象iter1、iter2...元素，返回新的可迭代对象，其元素为各系列iter1、iter2...对象元素组成的元组
# 如果各系列长度不一致，则截断至最小系列长度

zip;
zip((1, 2, 3), 'abc', range(3));        # <zip object at 0x02C47BC0>
list(zip((1, 2, 3), 'abc', range(3)))   # [(1, 'a', 0), (2, 'b', 1), (3, 'c', 2)]
list(zip('abc', range(10)))             # [('a', 0), ('b', 1), ('c', 2)]

# 取最大长度
import itertools
list(itertools.zip_longest('ABCD', fillvalue = '-'))

# enumerate迭代器
# enumerate用于枚举可迭代对象iterable中的元素，返回元素为元组（计数， 元素）的可迭代对象。

list(enumerate('ABCD', start=10001))

# enumerate_lineno.py
def printfilewithlineno(path):
    with open(path, 'r', encoding='urt8') as f:
        lines = f.readlines()
    for idx, line in enumerate(lines):
        print(idx, line)

# testing code
if __name__ == '__main__':
    thisfile = __file__
printfilewithlineno(thisfile)

# itertools模块和迭代器函数

# 无穷系列迭代器

# count(start = 0, step = 1)    # 从start开始，步长为step的无穷系列
# cycle(iterable)               # 可迭代对象iterable元素的无限重复
# repeat(object [, times])      # 重复对象object无数次（若指定times，则重复times）

from itertools import *
list(zip(count(1), 'abcde'))
list(zip(range(10), cycle('abc')))
list(repeat('God', 5))

# 累计迭代器accumulate
# accumulate[iterable[, func]]
import itertools
list(accumulate((1, 2, 3, 4, 5)))   # 结果元素为1， 1+2， 1+2+3，
list(accumulate((1, 2, 3, 4 ,5), operator.mul))

# 级联迭代器
# chain(* iterables)
# 连接多个可迭代对象的元素，作为一个系列
import itertools
list(itertools.chain(1, 2, 3), 'abc', range(5))
# chain的类工厂函数chain.from_iterable(iterables)，也可用于连接多个系列
list(itertools.chain.from_iterable(['ABC'], 'DEF'))

# 选择压缩迭代器
# compress(data, selectors)
# 根据选择器selectors的元素
import itertools
list(itertools.compress('ABCDEF', [1, 0, 1, 0, 1, 1]))      # ['A', 'C', 'E', 'F']

# 截取迭代器dropwhile和takewhile
# dropwhile(predicate, iterable)根据条件函数predicate处理可迭代对象的每个元素，丢弃iterable的元素，直至条件函数的结果为True
# takewhile(predicate, iterable)根据条件函数predicate处理可迭代对象的每个元素，返回iterable的元素，直至条件函数的结果为False
import itertools
list(itertools.dropwhile(lambda x : x < 5, [1, 4, 6, 4, 1]))
list(itertools.takewhile(lambda x : x < 5), [1, 4 , 6, 4, 1])


# 切片迭代器islice
# islice(iterable, stop)
# islice(iterable, start, stop[, step])

import itertools
list(itertools.islice('ABCDEFG', 2))
list(itertools.islice('ABCDEFG', 2, 4))
list(itertools.islice('ABCDEFG', 2, None))
list(itertools.islice('ABCDEFG', 0, None, 2))


# 迭代器groupby
# groupby(iterable, key = None)
import itertools
data = [1, -2, 0, 0, -1, 2 ,1, -1, 2, 0, 0]
data1 = sorted(data, key=abs)
for k, g in itertools.groupby(data1, key=abs):
    print(k, list(g))

# 返回多个迭代器tee
# 返回可迭代对象iterable的n个（默认为2）迭代器
import itertools
for i in itertools.tee(range(10), 3):
    print(list(i))

# 组合迭代器combinations/combinations_with_replacement
# combinations(iterable, r)
# combinations_with_replacement(iterable, r)
# 返回可迭代对象iterable的元素的组合，组合长度为r
import itertools
list(itertools.combinations([1, 2, 3,], 2))         # [(1, 2), (1, 3), (2, 3)]
list(itertools.combinations([1, 2, 3, 4], 3))       # [(1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)]
list(itertools.combinations_with_replacement([1, 2, 3], 2))     # [(1, 1), (1, 2), (1, 3), (2, 2), (2, 3), (3, 3)]

# 排列迭代器permutations
# 返回可迭代对象iterable的元素的排列，排列长度为r
import itertools
list(itertools.permutations([1, 2, 3], 2))      # [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]
list(itertools.permutations([1, 2, 3]))         # [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

# 笛卡尔积迭代器
# product(*iterables, repeat=1)
# 返回迭代对象的笛卡尔积，repeat为可迭代对象的重复次数
import itertools
list(itertools.product([1, 2], 'abc'))
list(itertools.product([1, 2], repeat=3))

















