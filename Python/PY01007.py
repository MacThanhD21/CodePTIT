import math

T = int(input())

for _ in range(T):
    N, X, M = map(float, input().split())
    
    numYea = 0
    
    while N < M:
        interet = (X / 100) * N
        N += interet
        numYea += 1
        
    print(numYea)
    
