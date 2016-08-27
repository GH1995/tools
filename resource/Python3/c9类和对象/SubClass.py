# SubClass.py
class Dimension:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def area(self):
        pass

class Circle(Dimension):
    def __init__(self, r):
        Dimension.__init__(self, r, 0)
    def area(self):
        return 3.14*self.x*self.x

class Rectangle(Dimension):
    def __init__(self, w, h):
        Dimension.__init__(self, w, h)
    def area(self):
        return self.x*self.y
    
    
d1 = Circle(2.0)
d2 = Rectangle(2.0, 4.0)

print(d1.area(), d2.area())