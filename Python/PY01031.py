

F = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for _ in range(int(input())):
    N, b = [int(x) for x in input().split()]
    
    s = ""
    while N > 0:
        s = F[N % b] + s
        N //= b
    print(s)