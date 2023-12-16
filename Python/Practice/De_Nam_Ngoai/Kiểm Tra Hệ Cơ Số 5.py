

res = ['0', '1', '2', '3', '4']

for _ in range(int(input())):
    s = input()
    try:
        a = [int(x) for x in " ".join(s).split()]
    except:
        pass
    ok = True
    for x in s:
        if x not in res:
            print("NO")
            ok = False
            break
    if ok and sum(a) == 5:
        print("YES")