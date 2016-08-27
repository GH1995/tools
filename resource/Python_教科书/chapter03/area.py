#chapter03\area.py
import math
a = float(input("请输入三角形的边长a："))
b = float(input("请输入三角形的边长b："))
c = float(input("请输入三角形的边长c："))
p = (a + b + c) / 2#三角形周长的一半
area = math.sqrt(p*(p-a)*(p-b)*(p-c));#三角形面积
print(str.format("三角形三边分别为：a={0},b={1},c={2}", a, b, c))
print(str.format("三角形的面积 = {0}", area))
