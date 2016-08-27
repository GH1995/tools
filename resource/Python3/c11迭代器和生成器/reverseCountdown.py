# reverseCountdown.py
class Countdown:
    def __init__(self, start):
        self.start = start

    # 正向迭代
    def __iter__(self):
        n = self.start
        while n > 0:
            yield n
            n -= 1
    
    # 反向迭代
    def __reversed__(self):
        n = 1
        while n <= self.start:
            yield n
            n += 1
# testing code
if __name__ == '__main__':
    for i in Countdown(10):print(i, end=' ')
    for i in reversed(Countdown(10)):print(i, end=' ')