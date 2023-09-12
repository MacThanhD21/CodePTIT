
from math import prod

if __name__ == '__main__':
    t = 1
    t = int(input())
    for _ in range(t):
        s = input()
        a = [int(x) for x in s]
        
        check_odd = all(num == 0 for idx, num in enumerate(a) if idx % 2 == 0)
        
        if check_odd: print("0", end = " ")
        else:
            tich = prod(num for idx, num in enumerate(a) if idx % 2 == 0 and num != 0)
            print(tich, end = " ")
        
        total = sum(num for idx, num in enumerate(a) if idx % 2 == 1)
        
        print(total)  
        
        