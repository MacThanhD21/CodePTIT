
while True:
    n = int(input())
    if n == 0: break
    Min, Max = 1000000000,0
    se = set()
    for i in range(n):
        x = int(input())
        se.add(x)
        Min = min(Min, x)
        Max = max(Max, x)
    if len(se) == 1: print("BANG NHAU")
    else: print(Min, Max, sep = " ")