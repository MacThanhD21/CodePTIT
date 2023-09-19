
def trans(s):
    sum = 0
    for x in s:
        #???
        sum += ord(x) - ord('0')
        sum += int(x)
    return str(sum)


s = input()
d = 0
while (len(s) > 1):
    s = trans(s)
    d += 1
print(d)
