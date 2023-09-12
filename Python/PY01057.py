import math

def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    p = 2
    while p * p <= n:
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
        
def prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        s = input()
        
        a = [int(x) for x in s]
        
        check1 = all(prime(int(num)) for idx, num in enumerate(a) if prime(idx))
        
        check2 = all(not prime(int(num)) for idx, num in enumerate(a) if not prime(idx))
        
        print("YES" if check1 and check2 else "NO")
        
        