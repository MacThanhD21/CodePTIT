def solve():
    n = int(input())
    u = [0] * (n + 1)
    v = [0] * (n + 1)

    for i in range(1, n + 1):
        u[i], v[i] = map(float, input().split())

    dp = [1] * (n + 1)
    ans = float('-inf')

    for i in range(1, n + 1):
        for j in range(1, i + 1):
            if u[j] < u[i] and v[j] > v[i]:
                dp[i] = max(dp[i], dp[j] + 1)
        ans = max(ans, dp[i])

    print(ans)

def main():
    TEST = 1
    TEST = int(input())
    for test in range(1, TEST + 1):
        solve()

if __name__ == "__main__":
    main()