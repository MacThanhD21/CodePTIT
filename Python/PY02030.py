import math

n = int(input())
ar = list(map(int, input().split()))
br = []
        
def prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True
for x in ar:
    if x not in br:
       br.append(x)
ok = False
for i in range(len(br)):
    if prime(sum(br[:i])) and prime(sum(br[i:])):
        print(i - 1)
        ok = True
        break
if not ok:
    print('NOT FOUND')