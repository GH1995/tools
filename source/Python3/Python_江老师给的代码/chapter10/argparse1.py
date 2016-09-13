#argparse1.py
import argparse
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', dest='outfile', help='output file')
    parser.add_argument(dest='filenames',metavar='filename', nargs='*')
    args = parser.parse_args()
    print(args.filenames)
    print(args.outfile)
if __name__ == '__main__':
    main()
