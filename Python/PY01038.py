
if __name__ == '__main__':
    for i in range(int(input())):
        s = int(input())
        
        step = 0
        ok = False
        
        while step <= 1000:
            step += 1
            if s % 7 == 0:
                ok = True
                print(s)
                break
            else:
                b = int(str(s)[::-1])
                s += b
        if not ok:
            print(-1)
            