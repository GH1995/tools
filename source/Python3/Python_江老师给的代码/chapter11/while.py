#while.py
t=(1,2,3,4,5,6,7,8,9,0)   #tuple
fetch=iter(t)           #获取迭代器
while True:
    try: i=next(fetch)
    except StopIteration: break
    print(i, end=' ')
