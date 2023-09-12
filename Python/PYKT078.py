
t = int(input())
for z in range(t) :
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    less_zero = []
    greater = []
    Max = max(a)
    
    idx = a.index(Max)
    a.insert(idx, k)
    
    for i in a :
        if i < 0 : less_zero.append(i)
        else : greater.append(i)
    for i in less_zero : print(i, end = " ")
    for i in greater : print(i, end = " ")
    print()
