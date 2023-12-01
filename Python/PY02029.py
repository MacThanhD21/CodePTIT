n, m = [int(x) for x in input().split()]

vote = [int(x) for x in input().split()]

dic, ans, Max = {0:0}, 0, 0
for x in vote:
    if x not in dic: dic[x] = 1
    else: dic[x] += 1
    Max = max(Max, dic[x])
tmp = 0
for i in range(1, m + 1):
    if i in dic and dic[i] > tmp and dic[i] < Max:
        tmp = dic[i]
        ans = i
if ans == 0: print("NONE")
else: print(ans)