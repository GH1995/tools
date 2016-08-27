# global.py
pi = 3.1415
e = 2.71828
def my_func():
    global pi
    pi = 3.14
    print('globa pi = ', pi)
    e = 2.71
    print('local e = ', e)
    
print('module pi = ', pi)
print('module e = ', e)
my_func()
print('module pi = ', pi)
print('module e = ', e)
    