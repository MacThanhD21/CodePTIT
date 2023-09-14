import math

def prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True


if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        n = int(input())
        
        a = [int(x) for x in input().split()]
        
        b = []
        for x in a:
            if x not in b:
                b.append(x)
        
        ok = False
        for i in range(len(b)):
            if prime(sum(b[0:i])) and prime(sum(b[i:len(b) + 1])):
                print(i - 1)
                ok = True
                break
        if not ok:
            print("NOT FOUND")