# while.py
t = (1, 2, 3, 4 ,5, 6, 7 ,8, 9, 0)
fetch = iter(t)
while True:
    try:
        i = next(fetch)
        print(i, end=' ')
    except StopIteration:
        break
        