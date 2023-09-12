

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
    if n <= 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        s = input()
        
        a1 = [int(x) for x in s]
        
        check1 = all(num % 2 == 0 for idx, num in enumerate(a1) if idx % 2 == 0)
        
        check2 = all(num % 2 == 1 for idx, num in enumerate(a1) if idx % 2 == 1)
        
        total = sum(a1)
        
        if check1 and check2 and prime(total):
            print("YES")
        else:
            print("NO")
        