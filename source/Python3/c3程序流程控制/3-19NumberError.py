class NumberError(Exception):
    def __init__(self, data):
        Exception.__init__(self, data)
        self.data = data
    def __str__(self):
        return self.data + ':非法数值(<0)'

if __name__ == '__main__':
    raise NumberError('-123')