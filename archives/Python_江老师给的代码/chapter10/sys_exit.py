#sys_exit.py
import sys
def main(argv):
    if len(sys.argv) != 3:
        sys.stderr.write('参数个数必须为2')
        raise SystemExit(1)
    print('参数个数正确')
if __name__ == '__main__':
    main(sys.argv)
