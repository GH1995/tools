# TemperatureConverter.py
class TemperatureConverter:
    @classmethod
    def c2f(cls, t_c):
        t_c = float(t_c)
        t_f = (t_c*9/5) + 32
        return t_f

    @classmethod
    def f2c(cls, t_f):
        t_f = float(t_f)
        t_c = (t_f - 32)*5/9
        return t_c

# testing code
if __name__ == '__main__':
    print('1.从摄氏温度到华氏温度.')
    print('2.从华氏温度到摄氏温度.')
    choice = int(input('请选择转换方向：'))

    if choice == 1:
        t_c = float(input('请输入摄氏温度：'))
        t_f = TemperatureConverter.c2f(t_c)
        print('华氏温度为：{0:.2f}'.format(t_f))

    if choice == 2:
        t_f = float(input('请输入华氏温度：'))
        t_c = TemperatureConverter.f2c(t_f)
        print('摄氏温度为：{0:.2f}'.format(t_c))
