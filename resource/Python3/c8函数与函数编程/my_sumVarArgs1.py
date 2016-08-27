def my_sum3(a, b, *c):
    total = a + b
    for n in c:
        total += n
    return total
print(my_sum3(1, 2))
print(my_sum3(1, 2, 3, 4, 5))
print(my_sum3(1, 2, 3, 4, 5, 6, 7))