# deque_tail.py
import collections
def tail(filename, n = 10):
    'Return the last n lines of a file'
    with open(filename) as f:
        return collections.deque(f, n)

if __name__ == '__main__':
    path = r'deque_tail.py'
    dq = tail(path, n = 2)
    print(dq.popleft())
    print(dq.popleft())
