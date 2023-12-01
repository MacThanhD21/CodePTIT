n = int(input())

adj = {str(i) : 0 for i in range(1, n + 1)}

for _ in range(n - 1):
    u, v = input().split()
    adj[u] += 1
    adj[v] += 1

cnt = 0
for x in adj:
    if (adj[x]) == n - 1: 
        print('Yes')
        cnt = 1
        break
if not cnt: print('No')

