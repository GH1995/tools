import collections.abc
class ListBasedSet(collections.abc.Set):
     def __init__(self, iterable):
         self.elements = lst = []
         for value in iterable:
             if value not in lst:
                 lst.append(value)
     def __iter__(self):
         return iter(self.elements)
     def __contains__(self, value):
         return value in self.elements
     def __len__(self):
         return len(self.elements)
s1 = ListBasedSet('abcde')
s2 = ListBasedSet('defghi')
overlap = s1 & s2   #自动支持__and__()方法
for i in overlap:
    print(i)
