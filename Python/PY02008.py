

import math

def nt(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n) ) + 1):
        if n % i == 0:
            return False
    return True

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        N, X = list(map(int, input().split()))
        
        cnt = 0
        for i in range(10005):
            
            if nt(i):
                cnt += 1
                if cnt == N + 2:
                    break
                else:
                    print(X, end = " ")
                    X += i