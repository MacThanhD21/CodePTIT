# Cho một số nhị phân, người ta nhận ra quy tắc đơn giản là chỉ cần xét lần lượt các cụm ba chữ số nhị phân tình từ cuối của số đó, sau đó chuyển lần lượt từng cụm sang giá trị thập phân tương ứng thì kết quả nhận được chính là biểu diễn của số đó trong hệ cơ số 8. Nếu cụm cuối cùng bị thiếu thì bổ sung các chữ số 0 cho đủ 3 chữ số.

# Ví dụ:

# 11001100 => 011 | 001 | 100 => 314


binary_number = input().strip()
octal_number = oct(int(binary_number, 2))[2:]
print(octal_number)

