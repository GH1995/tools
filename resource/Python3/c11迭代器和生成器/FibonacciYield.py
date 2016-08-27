# FibonacciYield.py
def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield a

# tesing code
fibs = fib()
for f in fibs:
    if f < 1000:
        print(f, end = ' ')
    else:
        break