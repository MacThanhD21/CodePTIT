def count_digits(n, digit):
    count = 0
    while n > 0:
        last_digit = n % 10
        if last_digit == digit:
            count += 1
        n //= 10
    return count

def count_digits_dp(A, B, digit):
    dp = [0] * (B + 1)
    for i in range(1, B + 1):
        dp[i] = dp[i // 10] + count_digits(i, digit)
    
    if A == 0:
        return dp[B]
    else:
        return dp[B] - dp[A - 1]

T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    result = [count_digits_dp(A, B, digit) for digit in range(10)]
    print(*result)
