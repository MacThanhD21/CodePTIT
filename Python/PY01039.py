

if __name__ == '__main__':
    for _ in range(int(input())):
        s = input()
        
        tmp1 = set(s)
        ok = True
        if len(tmp1) != 2:
            ok = False
            
        for i in range(len(s) - 2):
            if len(tmp1) != 2 or s[i] != s[i + 2]:
                ok = False
                break
            
        if ok:
            print("YES")
        else:
            print("NO")