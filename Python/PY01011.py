def check(x):
    tmp = str(x)
    tmp1 = tmp[::-1]
    
    return tmp1 == tmp

def check1(x):
    while x:
        tmp = x % 10
        if tmp != 0 and tmp != 2 and tmp != 4 and tmp != 6 and tmp != 8:
            return False
        x //= 10
    return True

if __name__ == '__main__':

    t = int(input())
    
    for _ in range(t):
        n = int(input())
        # print(check1(22))

        for i in range(n):
            if i >= 22 and check(i) and check1(i) and len(str(i)) % 2 != 1:
                print(i, end = ' ')
            
        print()