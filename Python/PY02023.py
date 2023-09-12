

import math
from functools import reduce
import operator

def product_of_digits(number):
    return reduce(operator.mul, map(int, str(number)))

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(x) for x in input().split()]
        
        a.sort(key=lambda x: (product_of_digits(x), x)) # (sum, x) 2 tiêu chí sắp xếp
        print(*a)
        
