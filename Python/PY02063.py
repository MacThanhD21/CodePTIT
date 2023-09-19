

n = int(input())

a = sorted([int(x) for x in input().split()])

# TH có số âm
Max1 = max(a[0] * a[1], a[0] * a[1] * a[n - 1])

# TH toàn số dương
Max2 = max(a[n - 1] * a[n - 2] * a[n - 3], a[n - 1] * a[n - 2])

print(max(Max1, Max2))