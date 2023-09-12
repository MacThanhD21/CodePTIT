

for _ in range(int(input())):
    s = input()
    res = ""
    nho = 0
    for i in range(len(s) - 1, 0, -1):
        res = "0" + res
        if s[i] == '0' or (int(s[i]) + nho) % 10 == 0:
            nho = 0
        elif int(s[i]) + nho >= 5:
            nho = 1
        elif int(s[i]) + nho < 5:
            nho = -1
    if nho == 1 or nho == 0:
        res = str(int(s[0]) + nho) + res
    else:
        res = str(int(s[0])) + res
    print(res)
