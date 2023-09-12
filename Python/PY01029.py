


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
        

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        
        convert_n = int(str(n)[::-1])
        
        if gcd(n, convert_n) == 1:
            print('YES')
        else:
            print('NO')
            