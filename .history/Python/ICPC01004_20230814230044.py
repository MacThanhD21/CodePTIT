if __name__ == '__main__':
    t = int(input())
    for i in range(1, t + 1):
        s = input()

        s += "a"

        res = 0
        ans = 0

        for i in range(len(s)):
            if s[i].isdigit():
                res = res * 10 + int(s[i])
            else:
                if res != 0:
                    ans = max(ans, res)
                    res = 0
        print(ans)