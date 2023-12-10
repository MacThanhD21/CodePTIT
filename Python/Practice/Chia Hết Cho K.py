a, k, n = [int(x) for x in input().split()]

ok = False
for i in range(1, n - a + 1):
    if (a + i) % k == 0:
        print(i, end = ' ')
        ok = True
if not ok :
    print(-1)