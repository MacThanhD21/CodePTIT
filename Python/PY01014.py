

if __name__ == '__main__':
    a, K, N = list(map(int, input().split()))

    founded = False
    max_X = N // K
    
    for x in range (1, max_X + 1):
        b = K * x - a
        if b > 0:
            print(b, end = ' ')
            founded = True
            
    if not founded:
        print(-1)