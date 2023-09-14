
with open("DATA.txt") as obj:
	s = obj.read().split()

new_s = sorted(list(set([x.lower() for x in s])))

for x in new_s:
	print(x)