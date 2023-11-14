for _ in range(int(input())):
    s = input().split('.')
    
    ok = True
    
    if len(s) != 4:
        ok = False
    else:
        for x in s:
            if x.isdigit():
                if int(x) < 0 or int(x) > 255:
                    ok = False
                    break
            else:
                ok = False
                break
    if ok:
        print('YES')
    else:
        print('NO')