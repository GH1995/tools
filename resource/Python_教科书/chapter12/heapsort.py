#heapsort.py
from heapq import *
def heapsort(iterable):
    h = []
    for value in iterable:
        heappush(h, value)
    return [heappop(h) for i in range(len(h))]
#测试代码
if __name__ == '__main__':
    data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
    print(heapsort(data))
