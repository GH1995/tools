# PointInit.py
class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

p1 = Point()
print("p1({0}, {1})".format(p1.x, p1.y))

p1 = Point(5, 5)
print("p1({0}, {1})".format(p1.x, p1.y))