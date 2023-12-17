# Đọc dữ liệu từ file data1 và data2
with open('data1_binary', 'rb') as file1, open('data2_binary', 'rb') as file2:
    data1 = file1.read().decode('utf-8').split()
    data2 = file2.read().decode('utf-8').split()

# Tạo các tổ hợp dãy số khác nhau từ hai file
combinations = [a + b for a in data1 for b in data2]

# Sắp xếp theo thứ tự từ điển
sorted_combinations = sorted(combinations)

# In các tổ hợp đã tạo và đã sắp xếp
for combo in sorted_combinations:
    print(combo)
