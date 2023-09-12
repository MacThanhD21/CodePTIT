

import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        n = int(input())
        a = sorted(list(map(int, input().split())))
        
        for i in range(n - 1):
            for j in range(i + 1, n):
                if gcd(a[j], a[i]) == 1:
                    print(a[i], a[j], sep = " ")
            
        