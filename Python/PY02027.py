a = []
for _ in range(int(input())):
    s = input() + '@'
    res = ''
    for i in range(len(s)):
        if s[i].isdigit():
            res += s[i]
        else:
            if res != '':
                a.append(int(res))
                res = ''
for x in sorted(a):
    print(x)