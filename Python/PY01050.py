from datetime import *
from collections import *
import itertools
from math import *

N = int(input())
chr = ['A', 'B', 'C']

def check_1(s):
    return (s.count('A') <= s.count('B') and s.count('B') <= s.count('C'))
def check_2(s):
    return all(x in s for x in chr)

for i in range(3, N + 1):
    res = itertools.product(chr, repeat=i)
    for string in res:
        s = "".join(string)
        if check_1(s) and check_2(s):
            print(s)
