

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    marked_one = [0] * n
    marked_two = [0] * n

    res = -1e9
    for i in range(n):
        if a[i] >= res:
            res = a[i]
            marked_one[i] = 1
    res = 1e9
    for i in range(n - 1, -1, -1):
        if a[i] < res:
            res = a[i]
            marked_two[i] = 1
    cnt = 0
    for i in range(n):
        if marked_one[i] == 1 and marked_two[i] == 1:
            cnt += 1
    print(cnt)