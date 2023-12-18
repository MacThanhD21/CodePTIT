f = open('VANBAN.in')
data = f.read().split()

dic = {}
res = ""
max_Len = 0

for x in data:
    if x == x[::-1]:
        if len(x) > max_Len:
            max_Len = len(x)
            dic.clear()
            dic[x] = 1
        elif len(x) == max_Len:
            if x not in dic:
                dic[x] = 1
            else:
                dic[x] += 1
for x in dic:
    print(x, dic[x])