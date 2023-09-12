INF = float('inf')

def min_cost_to_reach(dest, n, a, c):
    dp = [INF] * (dest + 1)
    dp[0] = 0

    for i in range(dest + 1):
        if dp[i] != INF:
            for j in range(n):
                if i + a[j] <= dest:
                    dp[i + a[j]] = min(dp[i + a[j]], dp[i] + c[j])

    return dp[dest] if dp[dest] != INF else -1

def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        a = list(map(int, input().split()))
        c = list(map(int, input().split()))
        dest = max(a) * 200  # Lượng tiền tối đa cần phải trả
        result = min_cost_to_reach(dest, n, a, c)
        print(result)

if __name__ == "__main__":
    main()
