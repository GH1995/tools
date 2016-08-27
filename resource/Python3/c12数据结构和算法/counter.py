# counter.py
import collections, re
path = r'.\text.txt'
with open(path) as f:
    words = re.findall(r'\w+', f.read().lower())    # 读取文本内容，转化为小写
    c = collections.Counter(words)
    print(c.most_common(5))
