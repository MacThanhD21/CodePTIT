a = [1] * 1000001

def era():
    a[0] = a[1] = 0
    for i in range(2, 1000):
        if a[i] == 1:
            for j in range(i * i, 1000001, i):
                a[j] = 0

def rv(s):
    tmp = str(s)
    t = tmp[::-1]
    return int(t)

def check(s):
    tmp = str(s)
    t = tmp[::-1]
    if tmp == t:
        return True
    else:
        return False


era()

if __name__ == '__main__':
    TestCase = int(input())
    for _ in range(TestCase):
        
        n = int(input())
        for i in range(n):
            x = a[rv(i)]
            if a[i] == 1 and a[rv(i)] == 1 and not check(i) and rv(i) < n and i < rv(i) :
                print(i, rv(i), sep = ' ', end = ' ')
                
        print() 