
f = open('DANHSACH.in', 'r')
a = []

while True:
	try:
		s = f.readline().strip().title()
		if s == '': break
		a.append(s)
	except:
		break

a.sort(key=lambda x : (x.split()[-1], x.split()[0]))
for x in a:
	print(x)