def min_insertions_to_make_beautiful_sequence(n, arr):
    insertions = 0
    
    for i in range(1, n):
        max_val = max(arr[i], arr[i - 1])
        min_val = min(arr[i], arr[i - 1])
        
        while max_val > 2 * min_val:
            min_val *= 2
            insertions += 1
    
    return insertions

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        
        insertions = min_insertions_to_make_beautiful_sequence(n, arr)
        
        print(insertions)

if __name__ == "__main__":
    main()
