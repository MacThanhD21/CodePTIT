def convert(n, b):
    
    t = ""
    s = "0123456789ABCDEF"
    
    while n:
        t += s[n % b]
        n //= b
            
    return t[::-1]


t = int(input())
while t > 0:
    t -= 1
    b = int(input())
    n = int(input(), 2) # conver to integer value hệ 10
        
    print(convert(n, b))