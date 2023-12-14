
encode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

while True:
    a = input().split()
    if len(a) == 1:
        break
    K, s, res = int(a[0]), a[1], ""
    for x in s:
        res += encode[(encode.index(x) + K) % 28]
    print(res[::-1])
    