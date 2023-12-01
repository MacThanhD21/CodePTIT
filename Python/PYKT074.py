for _ in range(int(input())):
    ans = ''
    s = input().split()
    for x in s:
        if len(ans) + len(x) <= 100: 
            ans += x + " "
        else: break
    print(ans[:len(ans)-1])
    