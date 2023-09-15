def max_accuracy(N, U, P):
    DP = [0.0] * (N + 1)
    DP[0] = 1.0  # Initialize with 0 modules

    for i in range(1, N + 1):
        for j in range(int(U) + 1):  # Convert U to integer and adjust the range
            max_accuracy_for_i = 0.0
            for k in range(j + 1):
                max_accuracy_for_i = max(
                    max_accuracy_for_i, DP[i - 1] * (1 - P[i - 1]) + (DP[i - 1] + k) * P[i - 1]
                )
            DP[i] = max(DP[i], max_accuracy_for_i)

    return DP[N]

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        U = float(input())
        P = list(map(float, input().split()))
        result = max_accuracy(N, U, P)
        print(f"{result:.6f}")

if __name__ == "__main__":
    main()
