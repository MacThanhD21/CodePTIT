from math import gcd
for j in range(int(input())):
    a = {0: 0}
    b = [0]
    n = int(int(input()))
    l = list(map(int, input().split()))
    c = list(map(int, input().split()))
    for i in range(n):
        for p in b:
            d = gcd(p, l[i])
            cost = a[p] + c[i]
            if d not in a:
                a[d] = cost
                b.append(d)
            elif a[d] > cost:
                a[d] = cost
    if 1 not in a:
        a[1] = -1
    print(a[1])