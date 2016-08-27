#bisect_grade.py
import bisect
def grade(score, breakpoints=[60, 70, 80, 90], grades='FDCBA'):
    i = bisect.bisect(breakpoints, score)
    return grades[i]
#测试代码
if __name__ == '__main__':
    data = [33, 65, 77, 70, 89, 90, 100]
    for s in data: print(s, grade(s), end=',')
