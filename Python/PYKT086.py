import math

file = open("DATA.in", "r")

F = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']

n = int(file.readline())

for _ in range(n):
    original_b = int(file.readline())
    s = file.readline().strip()
    b = int(math.log(original_b) / math.log(2))
    
    while len(s) % b != 0:
        s = "0" + s
        
    for i in range(0, len(s), b):
        print(F[int(s[i:i + b], 2)], end="")
    print() 
