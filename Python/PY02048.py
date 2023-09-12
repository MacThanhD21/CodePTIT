

import math

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        n, k = list(map(int, input().split()))
        
        a = sorted([int(x) for x in input().split()])
        
        ans = 0
        
        # 1 2 3 4 6 7 9
        
        for i in range(1, n):
            if a[i] - a[i-1] > k:
                ans += 1
        print(ans + 1)
        