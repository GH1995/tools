#textread.py
with open(r'c:\python\data1.txt', 'r') as f:
    for s in f.readlines():
        print(s, end='')
