import pickle
with open('./dataobj.dat', 'wb') as f:
    s1 = 'hello'
    c1 = 1 + 2j
    t1 = (1, 2, 3)
    d1 = {'name':'Mary', 'age':19}
    pickle.dump(s1, f)
    pickle.dump(c1, f)
    pickle.dump(t1, f)
    pickle.dump(d1, f)
    