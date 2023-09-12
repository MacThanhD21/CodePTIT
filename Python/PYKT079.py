


import math

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(x) for x in input().split()]
        
        Min = min(a)
        Max = max(a)
        
        ans = 0
        for x in range(Min, Max + 1):
            if x not in a:
                ans += 1
        print(ans)
        