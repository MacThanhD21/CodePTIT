

if __name__ == '__main__':
    t = int(input())
    
    for _ in range(t):
        s = input()
        s1 = s[:2]
        
        s2 = s[-2:]
        
        if s1 == s2:
            print("YES")
            
        else:
            print("NO")
            
