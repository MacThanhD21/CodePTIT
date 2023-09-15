import re

# Đọc số lượng xâu ký tự
N = int(input())

# Khởi tạo danh sách để lưu các số
numbers = []

# Đọc các xâu ký tự và tìm các số bằng regex
for _ in range(N):
    s = input()
    
    # Sử dụng regex để tìm tất cả các số trong xâu
    matches = re.findall(r'0*[1-9][0-9]*', s)
    
    # Thêm các số tìm được vào danh sách
    numbers.extend([int(match) for match in matches])

# Sắp xếp danh sách các số
numbers.sort()

# In ra các số theo thứ tự sắp xếp
for number in numbers:
    print(number)
