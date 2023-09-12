

import math

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        s = input()
        odd_digits = [int(s[i]) for i in range(0, len(s), 2)]
        se = set(odd_digits)
        
        if len(s) % 2 != 0 and len(se) == 1 and s[0] != s[1]:
            print("YES")
        else:
            print("NO")