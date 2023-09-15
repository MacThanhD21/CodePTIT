

for _ in range(int(input())) :
    n = int(input())
    a = []
    
    for _ in range(n):
        x , y = [int(x) for x in input().split()]
        a.append((x, y))
        
    a.sort(key = lambda x: x[1])
    
    ans, res = 0, 0
    for i in range(n):
        if a[i][0] >= res:
            ans += 1
            res = a[i][1]
    print(ans)