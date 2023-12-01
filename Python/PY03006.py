n = int(input())
dic = {}
for i in range(n):
    s = input().lower()
    res = ''
    for x in s + '@':
        if x.isalpha(): res += x
        else: 
            if res != '':
                if res in dic: dic[res] += 1
                else: dic[res] = 1
                res = ''
ans = sorted(dic.items(), key=lambda x: (-x[1], x[0]))
for x in ans:
    print(x[0], x[1])