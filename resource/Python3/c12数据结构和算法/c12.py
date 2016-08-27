# 数据结构和算法

# ABC模块

# Abstract Base Classes，抽象基类
# ListBasedSet.py
import collections.abc
class ListBasedSet(collections.abc.Set):
    def __init__(self, iterable):
        self.elements = lst = []

        for value in iterable:
            if value not in lst:
                lst.append(value)

    def __iter__(self):
        return iter(self.elements)

    def __contains__(self, value):
        return value in self.elements

    def __len__(self):
        return len(self.elements)

s1 = ListBasedSet('abcde')
s2 = ListBasedSet('defghi')
overlap = s1 & s2
for i in overlap:
    print(i)

# Container             __call__
# Hashable              __hash__
# Iterable
# Sized
# Callable
# Sequence
# MutableSequence
# Set
# MutableSet
# Mapping
# MutableMapping
# MappingView
# ItemsView
# KeysView
# ValuesView

# collections模块和容器类型

# ChainMap对象
# ChainMap(*maps)
# cmap.maps
# cmap.parents
# cmap.new_child()
from collections import *
m1 = {'a':1, 'b':2};
m2 = {'a':2, 'x':3, 'y':4};
m = ChainMap(m1, m2)
m.maps
m.parents
m.new_child()
m['a']
m['x']

# ChainMap.py
import os, argparse
from collections import *
defaults = {'color':'red', 'user':'guest'}
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--user')
parser.add_argument('-c', '--color')
namespace = parser.parse_args()
command_line_args = {k:v for k, v in vars(namespace).items() if v}
combined = ChainMap(command_line_args, os.environ, defaults)
print(combined['color'])
print(combined['user'])

# Counter对象
# Count([iterable-or-mapping])
# 用于统计各元素的计数，结果为map
from collections import *
c1 = Counter()
c2 = Counter('banana')
c3 = Counter({'red':4, 'bule':2})
c4 = Counter(cats = 4, dogs = 8)

# c.elements()  # 返回元素列表,各元素重复的次数为其计数
# c.most_common([n])    # 返回计数值最大的n个元素的元组（元素，计数）列表
# c.subtract([iterable-or-mapping])      # 元素的计数值减去系列或字典中对应元素的计数

# counter.py
import collections, re
path = r'.\text.txt'
with open(path) as f:
    words = re.findall(r'\w+', f.read().lower())    # 读取文本内容，转化为小写
    c = collections.Counter(words)
    print(c.most_common(5))

# deque对象
# deque(iterable[, maxlen])
# dq.append(x)
# dq.appendleft(x)
# dq.pop()
# dq.popleft()
# dq.extend(iterable)
# dq.extendleft(iterable)
# dq.remove(value)
# dq.count(x)
# dq.clear()
# dq.reverse()
# dq.rotate(n)  # 如果n>0，所有元素向右移动n个位置（循环）

# deque_tail.py
import collections
def tail(filename, n = 10):
    'Return the last n lines of a file'
    with open(filename) as f:
        return collections.deque(f, n)

if __name__ == '__main__':
    path = r'deque_tail.py'
    dq = tail(path, n = 2)
    print(dq.popleft())
    print(dq.popleft())

# deque_moving_average.py
import collections, itertools
def moving_average(iterable, n = 3):
    # moving_average([40, 30, 50, 46, 39, 44])-->40.0, 42.0, 45.0, 43.0
    # http://en.wikipedia.org/wiki/Moving_average
    it = iter(iterable)
    d = collections.deque(itertools.islice(it, n - 1))
    d.appendleft(0)
    s = sum(d)
    for elem in it:
        s += elem - d.popleft()
        d.append(elem)
        yield s/n

if __name__ == '__main__':
    data = [40, 30, 50, 46, 39, 44]
    list1 = list(moving_average(data, n = 3))
    print(list1)

# defaultdict对象
s = [('r', 1), ('g', 2), ('b', 3)]
dd = defaultdict(int, s)

# OrderedDict对象
# 记录字典元素插入的顺序

# namedtuple对象
from collections import *
p = namedtuple('Point', ['x', 'y'])
print(p._fields)

# namedtuple.py
from collections import *
import csv
EmployeeRecord = namedtuple('EmployeeRecord', 'name, age, title, department, paygrade')
for emp in map(EmployeeRecord._make, csv.reader(open("employee.csv"))):
    print(emp.name, emp.title)

# UserDict、UserList和UserString对象



# array.array对象
# array(typecode[, initializer])
import array
arr1 = array.array('b', [1, 22, 3, 4, 5])
arr1[1] = 22;
arr1[2:]

# array对象的方法

# heapq模块和堆队列算法
# 堆的基本操作
# heap = [];                  # 空堆
# heapq.heapify(alist):       # 将列表转换为堆
# heapq.heappush(heap, item)
# heapq.heappop(heap)
# heapq.heappushpop(heap, item)
# heapq.heapreplace(heap, item)

# heapsort.py
from heapq import *
def heapsort(iterable):
    h = []
    for value in iterable:
        heappush(h, value)
    return [heappop(h) for i in range(len(h))]

# testing code
if __name__ == '__main__':
    data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
    print(heapsort(data))

# heapq模块中基于heap的通用函数
# heapq.merge(* iterables)
# heapq.nlargest(n, iterable, key = None)
# heapq.nsmallest(n, iterable, key = None)


# bisect模块和二分排序算法

# bisect_grade.py
import bisect
def grade(score, breakpoints = [60, 70, 80, 90], grades = 'FDCBA'):
    i = bisect.bisect(breakpoints, score)
    return grades[i]

# testing code
if __name__ == '__main__':
    data = [33, 65, 77, 70, 89, 90, 100]
    for s in data:
        print(s, grade(s), end=',')

