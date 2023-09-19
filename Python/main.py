import math


def prime(n):
    if n < 2:
        return 0
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return 0
    return 1


n, m = map(int, input().split())

for i in range(n):
    a = list(map(int, input().split()))
    for j in a:
        print(prime(j), end=' ')
    print()
