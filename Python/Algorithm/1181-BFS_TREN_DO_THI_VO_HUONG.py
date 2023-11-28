
adj = [[] for _ in range(1005)]
used = [False for _ in range(1005)]

def bfs(u):
    q = [u]
    used[u] = True
    while q:
        u = q.pop(0)
        print(u, end = " ")
        for v in adj[u]:
            if not used[v]:
                q.append(v)
                used[v] = True

for _ in range(int(input())):
    n, m, u = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    for i in range(0, len(a) - 1, 2):
        adj[a[i]].append(a[i + 1])
        adj[a[i + 1]].append(a[i])
    bfs(u)
    for i in range(1, n + 1):
        used[i] = False
        adj[i] = []
    print()