for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    ok = 0
    for i in range(n):
        for j in range(i + 1, n):
            