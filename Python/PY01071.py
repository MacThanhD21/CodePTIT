

if __name__ == '__main__':
    def is_python_file(filename):
        return filename.lower().endswith('.py')

    s = input()
    if is_python_file(s):
        print("yes")
    else:
        print("no")