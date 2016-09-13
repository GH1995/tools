# 字典

# 创建字典对象

d = {1:'food', 2:'drink', 3:'fruit'}

# dict()
# dict(** kwargs)     # 使用关键字参数，创建一个新的字典
# dict(mapping)       # 从一个字典对象创建一个新的字典
# dict(iterable)      # 使用序列，创建一个新的字典

{}
{'a':'apple', 'b':'boy'}

dict()
dict({1:'food', 2:'drink'})
dict([('id', '1001'), ('name', 'Jenny')])
dict(baidu = 'baidu.com', google = 'google.com')

# 字典的访问操作
# d[key]
# d[key] = value
# del[key]

# 字典的视图对象

d = {1:'food', 2:'drink', 3:'fruit'}

d.keys()
d.values()
d.items()

key in d
key not in d

len(d)      # item个数




# 集合
{1, 2, 1}
{1, 'a', True}
set()
frozenset()
set('Hello')
# 集合中不能包含内置可变对象，下面的错误
# {'a', [1, 2]}

s1 = {1, 2, '3'}
s2 = {'4', '5', 6}

s1.add(99)
s1 | s2     # 并
s1 & s2     # 交
s1 - s2     # 差
s1^s2       # 对称差集




