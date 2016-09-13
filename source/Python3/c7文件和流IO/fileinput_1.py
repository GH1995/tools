import fileinput
def main():
    txtfiles = glob.glob(r'./*.txt')
    with fileinput.input(files = txtfiles) as f:
        for line in f:
            print(f.filename(), f.lineno(), line, end = ' ')

if __name__ == '__main__':
    main()