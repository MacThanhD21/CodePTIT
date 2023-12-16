from itertools import combinations
N, K = map(int, input().split())
comb = sorted(set(list(map(int, input().split()))))
x = list(combinations(comb, K))
for a in x: print(*a)