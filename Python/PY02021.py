
for _ in range(int(input())):
    n, m, z = [int(x) for x in input().split()]
    a, b, c = [int(x) for x in input().split()], [int(x) for x in input().split()], [int(x) for x in input().split()]
    
    i, j, k, ok = 0, 0, 0, False
    while i < n and j < m and k < z:
        if a[i] == b[j] == c[k]:
            print(a[i], end = ' ')
            i += 1
            j += 1
            k += 1
            ok = True
        elif a[i] < b[j]:
            i += 1
        elif b[j] < c[k]:
            j += 1
        else:
            k += 1
    if not ok: print("NO")
    print()