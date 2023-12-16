res = []

def gen(s):
    if s.count('2') > len(s) // 2:
        res.append(s)
    if len(s) < 10:
        for i in '012':
            gen(s + i)

gen('1')
gen('2')

res.sort(key=lambda x: int(x))

for _ in range(int(input())):
    N = int(input())
    for i in range(N):
        print(res[i], end=' ')
    print()