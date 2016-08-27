help()
进入帮助系统
dir(__builtins__)
内置内容列表
type()
id()
immutable and mutable
del x


三种特殊的数据类型
NoneType
NotImplementType
EllipsisType

string格式化
string.format(value1, value2, value3, ...)
str.format(string, value1, value2, value3)
format(value, string)
string % (value1, value2, value3)

"学生人数{0}, 平均成绩{1}".format(15, 81.2)
str.format("学生人数{0}, 平均成绩{1:2.2f}", 15, 81.2)
format(81.2, "0.5f")
"学生人数%4d, 平均成绩%2.1f" % (15, 81)

集合{1, 2, 3}
字典{1:"one", 2:"two"}

>>> math.sin(2)
0.9092974268256817
>>> from math import sin
>>> sin(2)
0.9092974268256817

print(1, 2, 3)
print(1, 2, 3, sep = ',')

try...except..else...finally

