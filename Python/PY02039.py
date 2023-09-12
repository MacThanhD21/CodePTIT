

import math

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        n = int(input())
        matrix = [[int(x) for x in input().split()] for _ in range(n)]

        p = int(input())

        sum_Below, sum_Above = 0, 0
        
        for i in range(n) :
            for j in range(n) :
                if i < j : sum_Below += matrix[i][j]
                elif j < i : sum_Above += matrix[i][j]
        s = abs(sum_Below - sum_Above)
        if s <= p : print("YES")
        else : print("NO")
        print(s)
