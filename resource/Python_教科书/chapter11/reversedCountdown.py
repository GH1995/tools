#reversedCountdown.py
class Countdown:
    def __init__(self, start):
        self.start = start
    #正向迭代
    def __iter__(self):
        n = self.start
        while n > 0:
            yield n
            n -= 1
    #反向迭代
    def __reversed__(self):
        n = 1
        while n <= self.start:
            yield n
            n += 1
#测试代码
if __name__ == '__main__': #如果独立运行时，则运行测试代码
    for i in Countdown(10): print(i, end=' ')
    for i in reversed(Countdown(10)): print(i, end=' ')
