
adj = [[] for _ in range(1005)]
used = [False for _ in range(1005)]

def dfs(u):
    used[u] = True
    for v in adj[u]:
        if not used[v]:
            dfs(v)
            
n, m, X = [int(x) for x in input().split()]
for _ in range(m):
    x, y = [int(x) for x in input().split()]
    adj[x].append(y)
    adj[y].append(x)
dfs(X)
ok = 1
for i in range(1, n + 1):
    if not used[i]:
        print(i)
        ok = 0
if ok: print(0)