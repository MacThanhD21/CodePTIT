
with open("DATA.txt") as obj:
    s = obj.read().split()

dic = {}
res = ""
max_Len = 0

for x in s:
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

for s, fre in dic.items():
    print(s, fre)    
