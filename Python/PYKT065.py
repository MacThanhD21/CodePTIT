def count_numbers(L, R, N):
    def sieve(n):
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                for j in range(i*i, n + 1, i):
                    is_prime[j] = False
        return is_prime

    primes = sieve(N)
    count = 0

    for num in range(L, R + 1):
        if all(num % i != 0 for i in range(2, N + 1) if primes[i]):
            count += 1

    return count

while True:
    try:
        line = input()
        if line == "-1":
            break
        L, R = map(int, line.split())
        N = int(input())
        result = count_numbers(L, R, N)
        print(result)
    except EOFError:
        break
