import itertools

N, K = list(map(int, input().split()))
ar = sorted(set(input().split()))

list_names = list(itertools.combinations(ar, K))
for ar in list_names:
    print(*ar)