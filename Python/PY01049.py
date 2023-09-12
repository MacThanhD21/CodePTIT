
import math

def prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def check1(n):
    return prime(len((n)))

def check2(n):
    
    cnt1, cnt2 = 0, 0
    
    for x in n:
        tmp = int(x)
        if prime(tmp):
            cnt1 += 1
        else:
            cnt2 += 1
    
    if cnt1 > cnt2:
        return True
    else:
        return False


if __name__ == '__main__':
    for _ in range(int(input())):
        n = input()
        
        if check1(n) and check2(n):
            print("YES")
        else:
            print("NO")