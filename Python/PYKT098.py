
f = open('DATA.in', 'r')
a = []

for line in f:
    for x in line.split():
        try:
            res = int(x)
            if x > 2**63:
                a.append(x)
        except: a.append(x)
print(' '.join(sorted(a)))
f.close()