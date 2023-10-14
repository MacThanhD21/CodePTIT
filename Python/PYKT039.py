

for _ in range(int(input())):
    n = int(input())
    arr_1 = list(map(int, input().split()))
    arr_2 = list(map(int, input().split()))
    
    arr_1.sort(), arr_2.sort()
    ok = True
    for i in range(n):
        if arr_1[i] > arr_2[i]:
            ok = False
            break
    if ok:    
        print('YES')
    else:
        print('NO')
    
    