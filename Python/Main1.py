def solve(arr):
    n = len(arr)
    if n < 3:
        return 0
    
    min1 = 1000000000
    min2 = 1000000000
    min3 = 1000000000
    
    # Update dan dan
    
    for i in range(n):
        if arr[i] <= min1:
            min3 = min2
            min2 = min1
            min1 = arr[i]
        elif arr[i] <= min2:
            min3 = min2
            min2 = arr[i]
        elif arr[i] <= min3:
            min3 = arr[i]
    
    return min1 + min2 + min3

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))

    result = solve(arr)
    print(result)