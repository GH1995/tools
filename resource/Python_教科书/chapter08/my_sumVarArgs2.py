#my_sumVarArgs2.py
def my_sum4(a, b, *c, **d):
    total = a + b
    for n in c:
       total = total + n
    for key in d:
        total = total + d[key]
    return total
print(my_sum4(1, 2))
print(my_sum4(1, 2, 3, 4, 5))
print(my_sum4(1, 2, 3, 4, 5, male = 6, female = 7))
