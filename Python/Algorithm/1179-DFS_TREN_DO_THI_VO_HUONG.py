adj = [[] for _ in range(1005)]
used = [False for _ in range(1005)]

def dfs(u):
    used[u] = True
    print(u, end = " ")
    for v in adj[u]:
        if not used[v]:
            dfs(v)

for _ in range(int(input())):
    a = []
    while True:
        try:
            res = [int(x) for x in input().split()]
            a += res
        except Exception:
            break    
    if a == []:
        exit()    
    idx, k = 0, a[1]
    for i in range(0, len(a), (idx + 3 + 2 * k)):
        try:
            n, m, u = a[i], a[i + 1], a[i + 2]
            idx += 3 + 2 * k - 1
            if idx + 2 < len(a) - 1:
                k = a[idx + 2]
            for j in range(i + 3, idx, 2):
                # print(a[j], a[j + 1])
                adj[a[j]].append(a[j + 1])
                adj[a[j + 1]].append(a[j])
            dfs(u)
            for i in range(1, n + 1):
                used[i] = False
                adj[i] = []
            print()
        except Exception:
            break