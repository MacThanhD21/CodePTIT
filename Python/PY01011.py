for _ in range(int(input())):
    s = input()
    for res in range(22, int(s)):
        tmp = str(res)
        if all(x in ['0', '2', '4', '6', '8'] for x in tmp) and tmp == tmp[::-1] and len(tmp) % 2 != 1:
            print(res, end=" ")
    print()