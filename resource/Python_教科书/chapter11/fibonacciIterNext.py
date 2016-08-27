#fibonacci.py
class Fib:
    def __init__(self):
        self.a,self.b = 0,1 #前两项值
    def __next__(self):   #f(n)=f(n-1)+f(n-2)
        self.a,self.b = self.b,self.a+self.b
        return self.a
    def __iter__(self):
        return self
#测试代码
fibs = Fib()
for f in fibs:
    if f < 1000: print(f, end=',')
    else: break
