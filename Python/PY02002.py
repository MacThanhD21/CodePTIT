

import math

F = [0] * 93

def fibo():
    F[0], F[1], F[2] = 0, 1, 1
    for i in range(3, 93):
        F[i] = F[i - 1] + F[i - 2]
        
if __name__ == '__main__':
    fibo()
    t = 1
    t = int(input())
    for _ in range(t):
        a, b = list(map(int, input().split()))
        
        for i in range(a, b + 1):
            print(F[i], end = " ")
        print()