

n, k = [int(x) for x in input().split()]

dic = {}

for _ in range(n):
    s = input().lower() + "!"
    res = ""
    
    for c in s:
        if c.isalpha() or c.isdigit():
            res += c
        else:
            if res != "":
                if res in dic:
                    dic[res] += 1
                else:
                    dic[res] = 1
                res = ""

sorted_dic = sorted(dic.items(), key=lambda x: (-x[1], x[0]))

for key, value in sorted_dic:
    if value >= k:
        print(key, value)