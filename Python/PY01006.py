import re


T = int(input())

lucky_pattern = re.compile(r'^[47]*$')

for _ in range(T):
    N = input()
    if lucky_pattern.match(N):
        print("YES")
    else:
        print("NO")
