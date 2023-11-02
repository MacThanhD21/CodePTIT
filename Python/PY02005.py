# O(log(n))

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    merged = []
    i = j = 0

    while i < len(left_half) and j < len(right_half):
        if left_half[i] <= right_half[j]:
            merged.append(left_half[i])
            i += 1
        else:
            merged.append(right_half[j])
            j += 1

    merged += left_half[i:]
    merged += right_half[j:]

    return merged

def count_inversions(arr):
    if len(arr) <= 1:
        return arr, 0

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half, left_count = count_inversions(left_half)
    right_half, right_count = count_inversions(right_half)

    merged = []
    i = j = 0
    count = 0 + left_count + right_count

    while i < len(left_half) and j < len(right_half):
        if left_half[i] <= right_half[j]:
            merged.append(left_half[i])
            i += 1
        else:
            merged.append(right_half[j])
            j += 1
            count += len(left_half) - i

    merged += left_half[i:]
    merged += right_half[j:]

    return merged, count

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))

    _, inversions = count_inversions(A)
    print(inversions)

# O(n^2)

n = int(input())
s = 0
a = [int(x) for x in input().split()]
for i in range(0, n) :
    for j in range(i + 1, n) :
        if a[i] > a[j] : s += 1
print(s)
