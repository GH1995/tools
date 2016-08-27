# decorator3.py
def makebold(fn):
    def wrapper(*s):
        return "<b>" + fn(*s) + "</b>"
    return wrapper

def makeitalic(fn):
    def wrapper(*s):
        return "<i>" + fn(*s) + "</i>"
    return wrapper

@makebold
@makeitalic
def htmltags(str1):
    return str1

# 测试代码
print(htmltags('Hello'))
