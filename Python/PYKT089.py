

# Đọc trên nhiều dòng

n = int(input())
 
arr, odd, even, check_pos = [], [], [], [0] * n
while True:
    x = [int(x) for x in input().split()]
    arr += x
    if len(arr) == n:
        break
    

for i in range(n):
    if arr[i] % 2 == 1:
        odd.append(arr[i])
        check_pos[i] = 1
    else:
        even.append(arr[i])
        
odd.sort()
even.sort(reverse=True)
for i in range(n):
    if check_pos[i] == 1:
        print(odd[-1], end=" ")
        odd.pop()
    else:
        print(even[-1], end=" ")
        even.pop()

