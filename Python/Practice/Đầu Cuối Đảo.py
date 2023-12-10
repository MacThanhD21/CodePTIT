for _ in range(int(input())):
    s = input()
    print('YES' if s[0:2] == s[-2:][::-1] else 'NO')