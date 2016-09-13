# CallabeObj.py
class GDistance:
    def __init__(self, g):
        self.g = g
    def __call__(self, t):
        return (self.g * t**2)/2

# testing code
if __name__ == '__main__':
    e_gdist = GDistance(9.8)
    for t in range(11):
        print(format(e_gdist(t), "0.2f"), end='')