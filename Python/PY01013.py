import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def prime(n):
    if n < 2:
        return False

    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True

if __name__ == '__main__':
    for _ in range(int(input())):
        a, b = map(int, input().split())
        uclc = gcd(a, b)
        
        ans = sum(map(int, str(uclc))) # Tra ve 1 Object of map
        print(ans)
        
        if prime(ans):
            print("YES")
        else:
            print("NO")
