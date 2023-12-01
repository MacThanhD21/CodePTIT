from collections import defaultdict

def DFS(v, visited):
    visited[v] = True
    for i in graph[v]:
        if visited[i] == False:
            DFS(i, visited)

def countComponents(u):
    visited = [False] * (n + 1)
    visited[u] = True
    count = 0
    for i in range(1, n + 1):
        if visited[i] == False:
            DFS(i, visited)
            count += 1
    return count

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    max_components = -1
    vertex = -1
    for i in range(1, n + 1):
        components = countComponents(i)
        if components > max_components:
            max_components = components
            vertex = i
    print(vertex if max_components > 1 else 0)