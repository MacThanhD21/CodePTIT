


if __name__ == '__main__':
    for _ in range(int(input())):
        s = input()
        
        for i in range(len(s) - 1):
            if s[i] < '0' or s[i] > '9':
                x = int(s[i + 1])
                while x:
                    print(s[i], end = '')
                    x -= 1
        
        print()sd+