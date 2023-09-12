import math

def nto(n):
    if n < 2:
        return 0
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return 0
    return 1


import math

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        m = {}

        n = int(input())
        a = [int(x) for x in input().split()]
        
        for i in a:
            if nto(i) == 1:
                if i in m:
                    m[i] += 1
                else:
                    m[i] = 1
        for i in m:
            print(i, m[i])
