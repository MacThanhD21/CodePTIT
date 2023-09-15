

import math

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        dic = {}
        n = int(input())
        
        count = 0
        tmp = ""
        t = 1
        while n:
            n -= 1
            s = input()
            if s == "":
                dic[tmp] = count
                count = 0
                t = 0
            if t == 1:
                tmp = s
                # print(tmp)
            elif s != "":
                count += 1
            t += 1
            
        dic[tmp] = count
        for key, val in dic.items():
            print(f'{key}: {val}') 