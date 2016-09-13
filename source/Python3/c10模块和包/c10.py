# 第10章 模块和包

# 模块的导入和使用

# import 语句
#   模块名.成员名

# from ... import 语句
#   成员名

# __import__()内置函数
_m = __import__(name)

# 模块搜索路径sys.path

# dir()内置函数
# dir()             # 列举当前模块的所有成员
# dir(模块名)        # 列举模块的所有成员
# dir(class/object) # 列举对象的所以成员

# 模块的定义

# 变量、函数、类
# 主块：模块第一次导入时执行

# my_math1.py
P1 = 3.14
def add(x, y):
    return x + y
def sub(x, y):
    return x - y
def mul(x, y):
    return x*y
def div(x, y):
    return x/y

# testing code
if __name__ == '__main__':
    print('123+456=', add(123, 456))
    print('123-456=', sub(123, 456))
    print('123*456=', mul(123, 456))
    print('123/456=', div(123, 456))

# 模块的名称

# 当一个模块被用户单独运行时，其__name__的值为'__main__'，所以测试代码才有用

# my_math2.py
P1 = 3.14
def add(x, y):
    return x + y
def sub(x, y):
    return x - y
def mul(x, y):
    return x*y
def div(x, y):
    return x/y

# testing code
def main():
    print('123+456=', add(123, 456))
    print('123-456=', sub(123, 456))
    print('123*456=', mul(123, 456))
    print('123/456=', div(123, 456))

if __name__ == '__main__':
    main()

# 包的含义
# 只要文件夹包含一个特殊的文件：__init__.py，则Python解释器将该文件夹作为包。

# 命令行参数

# sys.argv与命令行参数

# sys_argv.py
import sys
def main(argv):
    for i in range(len(sys.argv)):
        print('sys.argv[{0}] = {1}'.format(i, sys.argv[i]))

if __name__ == '__main__':
    main(sys.argv)

# argparse和命令行参数解析

# argparse1.py
import argparse
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', dest = 'outfile', help = 'output file')
    parser.add_argument(dest = 'filename', metavar = 'filename', nargs = '*')
    args = parser.parse_args()
    print(args.filenames)
    print(args.outfile)

if __name__ == '__main__':
    main()

# 终止程序运行时返回消息

# sys_exit.py
import sys
def main(argv):
    if len(sys.argv) != 3:
        sys.stderr.write('参数个数必须为2')
        raise SystemExit(1)
    print('参数个数正确')
if __name__ == '__main__':
    main(sys.argv)
