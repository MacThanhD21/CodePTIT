
n = 0; m = 0; u = 0; v = 0

adj = [[] for _ in range(n + 1)]
used = [False] * (n + 1)
res = []
    
def dfs(u, ans):
    global res, used
    used[u] = True

    for x in adj[u]:
        if not used[x]:
            dfs(x, ans + str(x))
            used[x] = False
            if x == v:
                ans += str(v)
                res.append(ans)

def solve():
    global n, m, u, v, res, adj, used
    n, m, u, v = map(int, input().split())
    for i in range(1, n + 1):
        adj[i] = []
        used[i] = False
    res = []
    for i in range(m):
        x, y = map(int, input().split())
        adj[x].append(y)

    dfs(u, str(u))

    fre = [0] * 1005

    for x in res:
        for z in x:
            tmp = ""
            tmp += z
            z = int(tmp)
            fre[z] += 1

    anss = 0
    for i in range(1, n + 1):
        if i != u and i != v:
            if fre[i] == len(res):
                anss += 1
    print(anss)

t = int(input())
for _ in range(t):
    solve()
