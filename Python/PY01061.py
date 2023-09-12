


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
        n = input()
        if len(n) < 3: 
            print("NO")
            
        check1 = prime(len(n))
        
        cnt_Pri, cnt_NoPri = 0, 0
        
        for x in n:
            if(prime(int(x))):
                cnt_Pri += 1
            else:
                cnt_NoPri += 1
        check2 = cnt_Pri > cnt_NoPri

        if check1 and check2:
            print("YES")
        else:
            print("NO")