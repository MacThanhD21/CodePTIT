def find_odd_occurrence(A):
    result = 0
    for num in A:
        result ^= num
    return result

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    print(find_odd_occurrence(A))