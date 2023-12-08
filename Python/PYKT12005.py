
for _ in range(int(input())):
    n, C, D = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    arr.sort()
    ans1, ans2, cnt1, cnt2 = 0.0, 0.0, 0, 0
    for i in range(min(C, D)):
        if arr != []:
            ans1 += arr.pop()
    ans1 /= min(C, D)

    for i in range(max(C, D)):   
        if arr != []:
            ans2 += arr.pop()
    ans2 /= max(C, D)
    print("{:.6f}".format(ans1 + ans2))  