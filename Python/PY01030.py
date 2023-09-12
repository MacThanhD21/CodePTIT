
import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    N, k = list(map(int, input().split()))
    
    a = 10 ** (k - 1)
    b = 10 ** k
    
    cnt = 0
    for i in range(a, b):
        if gcd(i, N) == 1:
            print(i, end = ' ')
            cnt += 1
            
        if cnt == 10:
            print()
            cnt = 0
    
    