#factorial.py
def factorial(num):
    if num == 0:
        return 1
    else:
        return num * factorial(num - 1)
#测试代码
for i in range(10):print(factorial(i), end=' ')
