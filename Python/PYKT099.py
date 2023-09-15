with open('DATA1.txt') as obj1:
    with open('DATA2.txt') as obj2:
        s1 = set(obj1.read().lower().split())
        s2 = set(obj2.read().lower().split())


ans1 = sorted(s1 - s2)
ans2 = sorted(s2 - s1)

print(" ".join(ans1))
print(" ".join(ans2))


# # Hàm để đọc và trả về tập hợp các từ từ một tập tin
# def read_words_from_file(file_path):
#     with open(file_path, 'r') as file:
#         text = file.read().lower()  # Chuyển hết về chữ thường và đọc nội dung tập tin
#         words = text.split()  # Tách thành các từ
#         return set(words)  # Chuyển danh sách các từ thành tập hợp và loại bỏ các trùng lặp

# # Đọc tập hợp từ hai tập tin
# data1_words = read_words_from_file('DATA1.txt')
# data2_words = read_words_from_file('DATA2.txt')

# # Tìm các từ khác nhau trong tập hợp từ hai tập tin
# different_in_data1 = sorted(data1_words - data2_words)
# different_in_data2 = sorted(data2_words - data1_words)

# # In ra kết quả
# print(' '.join(different_in_data1))
# print(' '.join(different_in_data2))
