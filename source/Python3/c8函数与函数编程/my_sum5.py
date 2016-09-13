# reference:my_sum5.py
def my_sum(*, mid_score, end_score, mid_rate = 0.4):
    score = mid_score*mid_rate + end_score*(1 - mid_rate)
    print(format(score, '.2f'))
    
my_sum(mid_score=88, end_score=79)
my_sum(end_score=79, mid_score=88)