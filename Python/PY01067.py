res = []

g = ['0', '1', '2']

def check(s):
    freq = s.count('2')
    if freq > len(s) / 2:
        return True
    return False

def gen(s):
    if check(s):
        res.append(s)
    if len(s) < 4:
        for i in g:
            gen(s + i)

gen('2')
gen('1')

res = sorted([int(x) for x in res])

for _ in range(int(input())):
    N = int(input())
    for i in range(N):
        print(res[i], end=' ')
    print()

        