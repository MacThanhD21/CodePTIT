

if __name__ == '__main__':
    for _ in range(int(input())):
        N = input().strip()
        result = eval('*'.join(digit for digit in N if digit != '0'))
        print(result)
