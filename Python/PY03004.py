n = int(input())

dic = {}

for _ in range(n):
    s = input().lower() + ' '
    
    res = ''
    for x in s:
        if (x >= 'a' and x <= 'z') or (x >= '0' and x <= '9'):
            res += x
        else:
            if res != '':
                if res in dic:
                    dic[res] += 1
                else:
                    dic[res] = 1
                res = ''


sorted_dic = sorted(dic.items(), key=lambda x: (-x[1], x[0]))

for word, frequency in sorted_dic:
    print(f"{word} {frequency}")
