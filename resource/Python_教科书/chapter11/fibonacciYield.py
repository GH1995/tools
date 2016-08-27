#fibonacciYield.py
def fib():
    a,b = 0,1     #前两项值
    while 1:
        a,b = b,a+b
        yield a  #f(n)=f(n-1)+f(n-2)
#测试代码
fibs = fib()
for f in fibs:
    if f < 1000: print(f, end=',')
    else: break
