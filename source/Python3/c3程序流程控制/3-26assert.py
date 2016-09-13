# assert <布尔表达式>, <string>
# <string>可以省略，如果布尔表达式Fals输出string

a = int(input("请输入整数a:"))
b = int(input("请输入整数b:"))

assert b != 0, '除数不能为0'
c = a / b
print(a, '/', b, '=', c)

# python -O 禁用断言