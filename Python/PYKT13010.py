MOD = 10**9 + 7

# Function to calculate modular exponentiation
def power(x, y, mod):
    result = 1
    x = x % mod
    while y > 0:
        if y % 2 == 1:
            result = (result * x) % mod
        y = y // 2
        x = (x * x) % mod
    return result

# Function to calculate the expression S
def calculate_S(n, K):
    result = 0
    for i in range(1, K + 1):
        term1 = power(i, K, MOD)
        term2 = (n - i + 1) % MOD
        result = (result + (term1 * term2) % MOD) % MOD

    return result

# Read the number of test cases
T = int(input())

# Process each test case
for _ in range(T):
    n, K = map(int, input().split())
    result = calculate_S(n, K)
    print(result)
