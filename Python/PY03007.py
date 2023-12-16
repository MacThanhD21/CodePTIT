
s = ""
while True:
	try:
		s += input().strip()
	except EOFError:
		break

res = ""
for x in s.split():
    res += x.strip() + " "
res = res.split('.')
ans = ""
for tmp in res:
    tmp = tmp.strip()
    if tmp:
        ans += tmp[0].upper() + tmp[1:] + "\n"
print(ans)