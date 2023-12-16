

import math
from functools import reduce
import operator

def product_of_digits(number):
    return reduce(operator.mul, map(int, str(number)))

for _ in range(int(input())):
    n = input()
    a = [int(x) for x in input().split()]
    
    a.sort(key=lambda x: (sum([int(i) for i in str(x)]), x)) 
    print(*a)
    
# 1
# 8
# 143 43 22 99 7 9 1111 10000000