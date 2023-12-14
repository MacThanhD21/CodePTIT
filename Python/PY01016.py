for _ in range(int(input())):
    s = input()
    for i in range(len(s)):
        if s[i].isdigit():
            print(s[i - 1] * int(s[i]), sep='', end='')
    print()