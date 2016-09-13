# 创建int对象

int(x = 0)

int()
int(123)
int('456')
int(1.23)

i = -10

# 转换为二进制
bin(i)

# 返回i的二进制位数
i.bit_length()



# 浮点类型常量
float(123)
float('3.14')

# Decimal(高精度浮点数)

from decimal import Decimal
Decimal(value = '0', context = None)

a = Decimal('1.1')  # 最好使用字符串
b = Decimal('2.2')
c = Decimal('3.3')

(a + b) == c # True



# Faction类型（分数）
from fractions import Fraction

# 创建
Fraction(4, 6)
Fraction(1.25)
Fraction('3/12')


# complex类型（复数）
c = complex(4, 5)
c.conjugate()
c.real
c.imag

0j
2j
1 + 2j



# 强制转换
int(1.23)

# 一些函数
divmod(5, 3)    # 返回(1, 2)  5 / 3 = 1···2
sum((1, 2, 3))  # 6



# random模块和随机函数
import random
random.seed(1)      # 设置伪随机数生成器的种子
for i in range(5):
    print(random.randint(1, 5), end = ' ')




from random import *
seq = ['a', 'e', 'i', 'o', 'u']
choice(seq)     # 从非空序列seq中随机返回一个元素
sample(seq, 3)  # 随机返回k个元素的list
shuffle(seq)    # 混排列表,并不返回




