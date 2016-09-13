# factorial.py
def factorial(num):
    if num == 0:
        return 1
    else:
        return num*factorial(num - 1)
    
# testing code
for i in range(10):
    print(factorial(i), end = ' ')