# my_math2.py
P1 = 3.14
def add(x, y):
    return x + y
def sub(x, y):
    return x - y
def mul(x, y):
    return x*y
def div(x, y):
    return x/y

# testing code
def main():
    print('123+456=', add(123, 456))
    print('123-456=', sub(123, 456))
    print('123*456=', mul(123, 456))
    print('123/456=', div(123, 456))

if __name__ == '__main__':
    main()