
a = [1] * 1000001

def era():
    a[0] = a[1] = 0
    for i in range(2, 1000):
        if a[i] == 1:
            for j in range(i * i, 1000001, i):
                a[j] = 0

era()
t = int(input())
for i in range(t) :
    n = int(input())
    ans = 0
    for i in range(0, n - 6) :
        if a[i] == 1 and a[i + 6] == 1 and (a[i + 2] == 1 or a[i + 4] == 1) : 
            ans += 1
    print(ans)
