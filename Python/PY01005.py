


if __name__ == '__main__':
    t = 1
    
    for _ in range(t):
        n = input()
        
        cnt_4, cnt_7 = 0, 0
        
        for x in n:
            if x == '4':
                cnt_4 += 1
            elif x == '7':
                cnt_7 += 1
        
        if (cnt_4 + cnt_7) == 4 or (cnt_4 + cnt_7) == 7:
            print('YES')
        else:
            print('NO')
            