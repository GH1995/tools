#random_randint.py
import random
num1 = random.randint(1,100)    #随机产生一个1-100以内的整数
while True:
    guess = int(input('请猜一个整数(1-100):'))
    if guess == num1:
        print('您猜对了！')
        break
    else:
        if guess > num1: print('猜错了。提示：小一点。')
        else: print('猜错了。提示：大一点。')
