#sys_argv.py
import sys
def main(argv):
    for i in range(len(sys.argv)):
        print('sys.argv[{0}]={1}'.format(i, sys.argv[i]))
if __name__ == '__main__':
    main(sys.argv)
