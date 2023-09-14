
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
    n = int(input())
    a = [int(x) for x in input().split()]
    
    b = []
    for x in a:
        if x not in b:
            b.append(x) 
    
    idx = 0
    ok = False
    for i in range(len(b)) :
       if prime(sum(b[0:i])) and prime(sum(b[i:len(b)])):
           ok = True
           print(i - 1)
           break 
    if not ok:
        print("NOT FOUND")
    # print(*b)
    