import struct

def write_binary_file(file_path, numbers):
    with open(file_path, 'wb') as file:
        for num in numbers:
            # Chuyển đổi số nguyên thành dữ liệu nhị phân, sử dụng định dạng 'I' (unsigned int)
            binary_data = struct.pack('I', num)
            file.write(binary_data)

# Mảng các số nguyên để ghi vào file
array_of_numbers = [123, 456, 789, 1023, 2048]

# Đường dẫn đến file nhị phân
binary_file_path = 'output_binary_file.bin'

# Ghi mảng số nguyên vào file nhị phân
write_binary_file(binary_file_path, array_of_numbers)

print(f"File {binary_file_path} đã được tạo thành công.")
