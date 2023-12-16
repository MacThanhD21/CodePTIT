import math

def prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

def ucln(a, b):
    while a:
        a, b = b % a, a
    return b

for _ in range(int(input())):
    a, b = [int(x) for x in input().split()]
    sum = 0
    for x in str(ucln(a, b)): sum += int(x)
    print('YES' if prime(sum) == True else 'NO')