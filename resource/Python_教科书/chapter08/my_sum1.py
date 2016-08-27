#my_sum1.py
def my_sum1(mid_score, end_score, mid_rate = 0.4):
    score = mid_score * mid_rate + end_score * (1 - mid_rate)
    print(format(score, '.2f'))
my_sum1(88, 79) #
my_sum1(88, 79, 0.5) #
