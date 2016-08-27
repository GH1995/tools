def printfilewithlineno(path):
    with open(path, 'r', encoding='utf8') as f:
        lines = f.readlines()
    for idx, line in enumerate(lines):
        print(idx, line)
#测试代码
if __name__ == '__main__':
    thisfile = __file__
printfilewithlineno(thisfile)
