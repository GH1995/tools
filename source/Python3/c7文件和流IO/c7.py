# 文件和文件对象

# f = open(file, mode = 'r', buffering = -1, encoding = None)
# r（read）/w（write）/x（new）/a（append）/b（binary）/t（text）/+（update）
# 默认：rt

#try:
#    f = open(file, mode)
#    # operation
#except:
#    # except operation
#finally:
#    f.close()

# with语句和上下文管理协议
# contextmanager.__enter__()
# contextmanager.__exit__(exc_type, exc_val, exc_tb)

# 实现上下文管理协议的对象
#with context [as var]
    # operation
#with open(file, mode) as f:
    # operation

# 创建或打开文件对象
f1 = open('data1.txt', 'w')
f2 = open('data2.txt', 'x')
f3 = open('data1.txt', 'a')

# 写入字符串到文本文件
f = open('data.txt', 'w')

f.write('123\n')
f.writelines(['456\n', 'def\n'])
f.flush()

# 关闭文件
# 使用with语句保证关闭
with open('data1.txt', 'w') as f:
    # operation

# references：text\write.py

# 文件读取
f = open(r'./data.txt', 'r')
f.read()    # 读到文件尾，返回一个字符串
f.readline()    # 返回一个字符串
f.readlines()   # 返回一个字符串或者列表

# 文本文件按行迭代
for s in f:
    print(s, end = ' ')

# references：text\read.py
with open(r'./data.txt', 'r') as f:
    for s in f.readlines():
        print(s, end=' ')


# 二进制文件的读写
# references：binary/write.py
with open(r'./databin.dat', 'wb') as f:
    f.write(b'123')
    f.write(b'abc')

# references：binary/read.py
with open(r'./databin.data', 'rb') as f:
    b = f.read()
    print(b)



# 文件的随机访问
import os
f.seek(0, os.SEEK_END)



# os模块和文件访问

# 使用os模块提供的函数访问文件

# 创建或打开
fd = os.open('data.dat', (os.O_RDWR | os.O_CREAT | os.O_BINARY))    # 创建二进制文件，返回文件描述符

# 定位
os.lseek(fd, 0, SEEK_END)   # 定位到结束位置

# 读写数据
os.write(fd, b'hello')
os.lseek(fd, 0, SEEK_SET)
os.read(fd, 3)

os.fsync(fd)



# pickle模块和对象系列化（把object存为文件）
# reference:pickledump.py
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

# reference:pickleload.py
import pickle
with open(r'./dataobj.dat', 'rb') as f:
    o1 = pickle.load(f)
    o2 = pickle.load(f)
    o3 = pickle.load(f)
    o4 = pickle.load(f)

    print(type(o1), str(o1))
    print(type(o2), str(o2))
    print(type(o3), str(o3))
    print(type(o4), str(o4))

# 输入重定向和管道

# FileInput对象
import fileinput
with fileinput.input(file = ('spam.txt', 'eggs.txt')) as f:
    for line in f:
        process(line)


# references:fileinput_1.py
import fileinput
def main():
    txtfiles = glob.glob(r'./*.txt')
    with fileinput.input(files = txtfiles) as f:
        for line in f:
            print(f.filename(), f.lineno(), line, end = ' ')

if __name__ == '__main__':
    main()

# 输入重定向
# references:fileinput_2.py
import fileinput
def main():
    with fileinput.input() as f:
        for line in f:
            print(f.filename(), f.lineno(), line, end = '')

if __name__ == '__main__':
    main()


















