n, m = [int(x) for x in input().split()]

x = [-1, -1, -1, 1, 1, 1, 0, 0]
y = [-1, 0, 1, -1, 0, 1, -1, 1]

a = []

for i in range(n):
    a.append([int(x) for x in input().split()])

cnt = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == -1:
            for k in range(8):
                x_new, y_new = i + x[k], j + y[k]
                if x_new >= 0 and x_new < n and y_new >= 0 and y_new < m:
                    if a[x_new][y_new] >= -1:
                        if a[x_new][y_new] == -1:
                            cnt += a[x_new][y_new]
                        else:
                            cnt += a[x_new][y_new]
                            a[x_new][y_new] = -2
print(cnt)
