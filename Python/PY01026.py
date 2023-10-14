
for test in range(1, int(input()) + 1):
    print("Test " + str(test) + ":", end = " ")
    s1 = list(input())
    s2 = list(input())
    s1.sort()
    s2.sort()
    if s1 != s2:
        print('NO')
    else:
        print('YES')