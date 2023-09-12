

import math

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        s = input()
        t = sorted(s)
        
        total_digit = str(sum([int(x) for x in t if x >= '0' and x <= '9']))

        r = [str(x) for x in t if x < '0' or x > '9']
        r = ''.join(r) 
        r += total_digit

        print(r)  