# 序列（sequence）类型bytes、bytearray、（字节数据）list（列表）、str（字符串）和tuple(元组)

str = 'acdef'
tuple = ('a', 'e', 'i', 'o', 'u')
list = [1, 2, 3, 4, 5]
# bytearray b = b'ABCDEF'

# 系列的切片问题
str[1:3]
str[3:10]
str[:2]
str[::-1]   # step

slice()     # slice对象可以保存用于切片的下标信息
slice1 = slice(1, len(str), 2)
str[slice1]
slice1.start, slice1.stop, slice1.step
slice1.indices(4)

# sequenece的连接和重复操作
s1 = 'abc'
s2 = 'xyz'
s1 + s2
s1*3
s1 *= 3

# sequence的成员关系操作
x = 1
s = [1, 2, 3, 4]

x in s
x not in s
s.count(x)      # 返回x在s（指定范围[start, end]）中出现的次数
s.index(x)      # 返回x在s（指定范围[start, end]）中第一次出现的下标


# sequence的比较运算操作符
s1 = 'abc'
s2 = 'abcd'
s1 < s2

# sequence的排序操作
s1 = 'axd'
sorted(s1)
sorted(s1, reverse = True)

# sequence长度、最大值、最小值、求和
s = 'abavadfaf'
len(s)
max(s)
min(s)

all([1, 2])     # 如果序列的所有值都为True返回True
any([1, 2])     # 如果序列的任意值都为True返回True

# 系列拆封
#{
#  变量的个数和系列长度相等
# a, b = (1, 2)

# 变量的个数和系列长度相等
first, *middles, last = range(10)

# 使用临时变量`_`，这个比较有用
s = (1, 2, 3)
_, b, _ = s

#}

# 元组, 创建元组
1, 2, 3
(1, 2, 3)
tuple([1, 2, 3])    # 由一个列表创建

# 列表
s = [1, 2, 3, 4]
list(range(1, 4))
list([1, 2, 3])     # 由另一个列表创建

s[1] = 'r'
#
# del s[1]
# s[i:j] = tuple      # or list
# dd s[i:j]           # eq s[i:j] = []
# s[i:j] = []


# method
s = [1, 3, 2]
s.append(x)
s.clear()
s.copy()
s.extend()
s.insert(i ,x)
s.pop()
s.pop(2)
s.remove(x)
s.reverse()
s.sort()


# 列表解析表达式   !奇妙，好用
[i**2 for i in range(10)]
[i for i in range(10) if i%2 == 0]
[(x, y, x*y) for x in range(1, 4) for y in range(1, 4) if x >= y]


# 字符串常量
print(r'c:\n')
# 创建str对象
str(complex(1, 2))

# str对象的方法
s = 'abc'
s.upper()       # object s' mrnthod
str.upper(s)    # class str's method

# 大小写转化
str.capitalize()
str.lower()
str.swapcase()
str.title()

# 填充、空白和对齐
chars = 'ab'
str.strip([chars])      # 去两边空格，也可指定去除的字符列表

# 测试，查找和替换
str.startswith()
str.endswith()
str.count()
str.index()
str.rindex()
str.find()
str.replace()

# 拆分合组合
str.split()
str.rsplit()
str.partition()
str.rpartition()
str.splitlines()
str.join()


# 翻译和转换
str.maketrans()
str.translate()


# important
# %元运算符形式
'结果：%f' % 88
'姓名：%s, 年龄：%d, 体重：%3.2f' % ('张三', 20, 53)
'%(lang)s has %(num) 03d quote types. ' % {'lang':'Python', 'num':2}

# format内置函数
format(81.2, "0.5f")
format(81.2, "%")

# 字符串的format方法
"int:{0:d};hex:{0:x};oct:{0:o};bin{0:b}".format(100)
'{2}, {1}, {0}'.format('a', 'b', 'c')
str.format_map('{name:s}, {age:d}, {weight:3.2f}', {'name':'Mary', 'age':20, 'weight':49})
