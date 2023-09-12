def min_steps_to_equalize_array(arr):
    n = len(arr)

    # Tính giá trị trung bình ban đầu
    initial_median = sorted(arr)[n//2]

    # Tìm giá trị trung bình đầu tiên theo thứ tự xuất hiện trong dãy ban đầu
    median = -1  # Giá trị mặc định nếu không tìm thấy
    for num in arr:
        if num == initial_median:
            median = num
            break

    # Tính tổng số bước để biến đổi dãy về giá trị trung bình
    total_steps = 0
    for num in arr:
        total_steps += abs(num - median)

    return total_steps, median

# Đọc dữ liệu đầu vào
n = int(input())
arr = list(map(int, input().split()))

# Gọi hàm và in kết quả
result, median = min_steps_to_equalize_array(arr)
print(result, median)
