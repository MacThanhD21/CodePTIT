import math

n = int(input())
arr = [int(x) for x in input().split()]

res, val = 1000000000, 0
for i in range(n):
    x = 0
    for j in range(n):
        x += abs(arr[i] - arr[j])
    if res > x:
        res = x
        val = arr[i]
print(res, val)