def my_max(a, b, *c): #求最大值
    max_value = a 
    if max_value < b:
        max_value = b
    for n in c:
        if max_value < n:
            max_value = n
    return max_value
print(my_max(1, 2))
print(my_max(1, 7, 11, 2, 5))
