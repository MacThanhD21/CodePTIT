if __name__ == '__main__':
    t = int(input())
    for i in range(1, t + 1):
        s = input()

        s += "a"

        res = 10**9
        ans = 10**9

        for i in range(len(s)):
            if s[i].isdigit():
                res = res * 10 + int(s[i])
            else:
                if res != 0:
                    ans = min(ans, res)
                    res = 0
        print(ans)