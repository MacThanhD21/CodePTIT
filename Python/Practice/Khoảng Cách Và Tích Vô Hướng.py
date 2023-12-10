import math
for _ in range(int(input())):
    X = [int(x) for x in input().split()]
    Y = [int(y) for y in input().split()]
    
    Euclid_Distance, tich = 0, 0
    for i in range(len(X)):
        Euclid_Distance += (X[i] - Y[i]) ** 2
        tich += X[i] * Y[i]
    print("{:.2f}".format(math.sqrt(Euclid_Distance)), tich) 