#counter.py
import collections, re
path = r'c:\python33\README.txt'
with open(path) as f:
    words = re.findall(r'\w+', f.read().lower())
    c = collections.Counter(words)
    print(c.most_common(5))
