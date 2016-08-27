# FibonacciIterNext.py
class Fib:
    def __init__(self):
        self.a, self.b = 0, 1
    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a
    def __iter__(self):
        return self

# testing code
fibs = Fib()
for f in fibs:
    if f < 1000:
        print(f, end = ',')
    else:
        break