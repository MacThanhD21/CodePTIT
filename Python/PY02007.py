

if __name__ == '__main__':
    x = 0
    s = set()
    while True :
        a = [int(x) for x in input().split()]
        x += len(a)
        
        for i in a :
            s.add(i % 42)
        if x == 10 : 
            break
        
    print(len(s))


