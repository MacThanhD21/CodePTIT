import numpy as np

def count_different_pairs(N, A):
    # Sử dụng NumPy để tạo mảng A_diff chứa sự khác biệt giữa các phần tử liền kề
    A_diff = np.diff(A)

    # Sử dụng NumPy để đếm số lượng giá trị khác 0 trong mảng A_diff
    count = np.count_nonzero(A_diff)

    return count

def main():
    N = int(input())
    A = list(map(int, input().split()))
    result = count_different_pairs(N, A)
    print(result)

if __name__ == "__main__":
    main()
