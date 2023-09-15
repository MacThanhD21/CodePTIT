MOD = 10**9 + 7

# Hàm tính lũy thừa a^b mod MOD
def power(a, b, MOD):
    result = 1
    a = a % MOD
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % MOD
        b = b // 2
        a = (a * a) % MOD
    return result

# Hàm tính tổng S = 1^K + 2^K + ... + n^K mod MOD bằng chia và trị
def calculate_S(n, K):
    if n == 0:
        return 0
    if n == 1:
        return 1

    # Chia thành hai nửa và tính tổng cho từng nửa
    half = n // 2
    left_half = calculate_S(half, K)
    right_half = calculate_S(n - half, K)

    # Tính tổng của hai nửa
    S = (power(half, K, MOD) * left_half + power(n - half, K, MOD) * right_half) % MOD

    return S

def main():
    T = int(input())
    for _ in range(T):
        n, K = map(int, input().split())
        result = calculate_S(n, K)
        print(result)

if __name__ == "__main__":
    main()
