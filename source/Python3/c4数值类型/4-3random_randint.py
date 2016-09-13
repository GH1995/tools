import random
num1 = random.randint(1, 100)
while True:
    guess = int(input('请猜一个整数（1~100）：'))
    if guess == num1:
        print('您猜对了')
        break
    else:
        if guess > num1:
            print('小一点')
        else:
            print('大一点')
