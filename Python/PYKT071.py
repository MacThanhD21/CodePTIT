import struct

def read_binary_list(filename):
    result = []
    
    with open(filename, 'rb') as file:
        while True:
            data = file.read(4)  # Đọc 4 byte
            if not data:
                break  # Kết thúc file
            value, = struct.unpack('I', data)  # Chuyển đổi byte sang số nguyên
            result.append(value)
    
    return result


def non_decreasing_numbers(nums1, nums2):
    result = []
    count1, count2 = 0, 0

    for num in sorted(set(nums1)):
        if all(int(digit) <= int(nums1[i + 1]) for i, digit in enumerate(str(num)[:-1])):
            count1 += nums1.count(num) if num in nums1 else 0
            result.append((num, count1, count2))
    for num in sorted(set(nums2)):
        if all(int(digit) <= int(nums2[i + 1]) for i, digit in enumerate(str(num)[:-1])):   
            count2 += nums2.count(num) if num in nums2 else 0
    result.append((num, count1, count2))
    return result

# Đọc dữ liệu từ hai file nhị phân
nums1 = read_binary_list('DATA1.in')
nums2 = read_binary_list('DATA2.in')

# Tìm và liệt kê các số không giảm
result = non_decreasing_numbers(nums1)

# In kết quả
for num, count1, count2 in result:
    print(f"{num} {count1} {count2}")


