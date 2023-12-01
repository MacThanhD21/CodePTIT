from collections import defaultdict

visited = [False] * (1005)
def DFS(v, i):
    visited[v] = True
    for x in graph[v]:
        if visited[x] == False and x != i:
            DFS(x, i)

t = int(input())
for _ in range(t):
    n, m, u, v = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
    count = 0
    for i in range(1, n + 1):
        if i != u and i != v:
            DFS(u, i)
            if visited[v] == False:
                count += 1
            visited = [False] * (n + 1)
    print(count)