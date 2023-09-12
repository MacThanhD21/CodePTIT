

if __name__ == '__main__':
    for _ in range(int(input())):
        n, k = [int(x) for x in input().split()]
        a = [int(x) for x in input().split()]
        
        b = a[k:n] + a[0:k]
        
        for x in b: 
            print(x, end = ' ')
        print()
