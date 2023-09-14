
n = int(input())
a = []
fre = [0] * 1005

Max = 0

while True:
    b = [int(x) for x in input().split()]
    a += b
    if len(a) == n:
        for i in range(n):
            fre[a[i]] = 1
        Max = max(a)
        break
    

ok = True
for i in range(1, Max + 1):
    if fre[i] == 0:
        print(i)
        ok = False
if ok:
    print("Excellent!")
    