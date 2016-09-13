#deque_moving_average.py
import collections, itertools
def moving_average(iterable, n=3):
    # moving_average([40, 30, 50, 46, 39, 44]) --> 40.0 42.0 45.0 43.0
    # http://en.wikipedia.org/wiki/Moving_average
    it = iter(iterable)
    d = collections.deque(itertools.islice(it, n-1))
    d.appendleft(0)
    s = sum(d)
    for elem in it:
        s += elem - d.popleft()
        d.append(elem)
        yield s / n
if __name__=='__main__':
    data = [40, 30, 50, 46, 39, 44]
    list1 = list(moving_average(data, n=3))
    print(list1)
