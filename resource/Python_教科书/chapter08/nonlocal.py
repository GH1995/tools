#nonlocal.py
def outer_func():
    tax_rate = 0.17 #局部变量示例
    print('outer fucnc tax rate =', tax_rate)
    def innner_func():
        nonlocal tax_rate
        tax_rate = 0.05
        print('inner func tax rate =', tax_rate)
    innner_func()
    print('outer fucnc tax rate =', tax_rate)
#测试代码
outer_func()
