
# import re

# s = ""
# regex = '[\w\s,:]+'
# while True:
#     try:
#         s += input()
#     except EOFError:
#         break
# s = re.findall(regex, s)
# for i in s:
#     x = i.lower().split()
#     x[0] = x[0].title()
#     print(' '.join(x))


import sys

s = ""
for line in sys.stdin:
    # print(line.strip())
    s += line.strip()

s = s.lower()
s = s.replace('?', '.')
s = s.replace('!', '.')

res = ""
for x in s.split():
    res += x.strip() + " "
res = res.split('.')
ans = ""
# print(res)
for tmp in res:
    tmp = tmp.strip()
    if tmp:
        ans += tmp[0].upper() + tmp[1:] + "\n"

print(ans)

