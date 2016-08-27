#try_except_rasie.py
from NumberError  import *
from raise_exception import *
if __name__=='__main__':
    try:
        data2 = (44, 78, 90, -80, 55)
        print('平均值=', average(data2))
    except NumberError as e:
        print('数值不能为负')
        raise e
