
n = int(input())

a, odd, even, fl = [], [], [], [0] * n
while True:
    x = [int(x) for x in input().split()]
    a += x
    if len(a) == n:
        break
for i in range(n):
    if a[i] % 2 == 0:
        even.append(a[i])
        fl[i] = 1
    else:
        odd.append(a[i])

odd.sort()
even.sort(reverse=True)
for i in range(n):
    if fl[i] == 1:
        print(even.pop(), end=' ')
    else:
        print(odd.pop(), end=' ')
