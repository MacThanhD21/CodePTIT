for _ in range(int(input())):
    s = input()
    if len(s) != 8:
        print('NO')
        pass
    else:
        ok = False
        for i in range(len(s)):
            if all(s[j] > s[j + 1] for j in range(i)) and all(s[j] < s[j + 1] for j in range(i, len(s) - 1)):
                print('YES')
                ok = True
                break
        if not ok:
            print('NO')
        