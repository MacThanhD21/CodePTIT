def count_digit_occurrences(a, b):
    def count_digit_dp(limit, digit):
        # Convert the limit to a string for easier manipulation
        limit_str = str(limit)
        n = len(limit_str)
        
        dp = [[0] * 10 for _ in range(n + 1)]
        
        for i in range(n + 1):
            for j in range(10):
                if i == 0:
                    dp[i][j] = 0
                elif i == 1:
                    if j <= int(limit_str[0]):
                        dp[i][j] = 1
                    else:
                        dp[i][j] = 0
                else:
                    for k in range(10):
                        if k < j:
                            dp[i][j] += dp[i - 1][k]
                        elif k == j:
                            dp[i][j] += dp[i - 1][k] + int(limit_str[i - 1]) + 1
                        else:
                            dp[i][j] += dp[i - 1][k] + 10 ** (i - 1)
        
        return dp[n][digit]

    occurrences = [0] * 10

    for digit in range(10):
        occurrences[digit] = count_digit_dp(b, digit) - count_digit_dp(a - 1, digit)

    return occurrences

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a, b = list(map(int, input().split()))
        occurrences = count_digit_occurrences(a, b)
        print(*occurrences)
