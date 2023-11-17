


if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())

        a = sorted(list(map(int, input().split())))
        b = sorted(list(map(int, input().split())))

        c, d = {}, {}

        for i in a:
            c[i] = 1
        for i in b:
            d[i] = 1

        if c == d:
            print("YES")
        else:
            print("NO")
