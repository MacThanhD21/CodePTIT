
import math

def is_prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

def sort_prime(arr):
    primes = []
    non_primes = []

    for num in arr:
        if is_prime(num):
            primes.append(num)
        else:
            non_primes.append(num)

    primes.sort()

    result = []
    prime_index = 0
    non_prime_index = 0

    for num in arr:
        if is_prime(num):
            result.append(primes[prime_index])
            prime_index += 1
        else:
            result.append(non_primes[non_prime_index])
            non_prime_index += 1

    return result

if __name__ == '__main__':
    N = int(input())
    
    A = list(map(int, input().split()))
    
    sorted_result = sort_prime(A)
    print(*sorted_result)