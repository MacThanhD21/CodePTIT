
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a == 1

if __name__ == '__main__':
    L, R = list(map(int, input().split()))
    
    for a in range(L, R - 1):
        for b in range(a + 1, R):
            for c in range(b + 1, R + 1):
                if gcd(a, b) and gcd(b, c) and gcd(c, a):
                    print(f"({a}, {b}, {c})")
    
    