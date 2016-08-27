#decorator3.py
def makebold(fn):
    def wrappper(*s):
        return "<b>" + fn(*s) + "</b>"
    return wrappper
def makeitalic(fn):
    def wrappper(*s):
        return "<i>" + fn(*s) + "</i>"
    return wrappper
@makebold
@makeitalic
def htmltags(str1):
    return str1
#测试代码
print(htmltags('Hello'))
