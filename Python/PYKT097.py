

while True:
    try:
        s = input().strip().capitalize().split()
        if s[-1][-1] != '.' and s[-1][-1] != '?' and s[-1][-1] != '!':
            s[-1] += '.'
        if len(s[-1]) == 1:
            s[-2] = s[-2] + s[-1]
            s.remove(s[-1])
        print(" ".join(s))

    except:
        break