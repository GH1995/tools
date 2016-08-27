#chapter02\getValue.py
def getValue(b,r,n): #定义函数getValue
    v = b*((1+r)**n) 
    return v
total = getValue(1000,0.05,5) #调用函数getValue
print(total) #打印结果
input()
