import csv

# Đếm số hàng và số cột trong tệp CSV
def count_rows_columns(filename):
    f = open(filename, "r")
    reader = csv.reader(f)
    rows = list(reader)  # Chuyển dữ liệu từ reader vào một danh sách
    for x in rows:
        for y in x:
            print(y, end = ' ')
        print()
    num_rows = len(rows)  # Đếm số hàng bằng cách đếm số phần tử trong danh sách
    num_columns = len(rows[0]) if rows else 0  # Đếm số cột của hàng đầu tiên, hoặc 0 nếu không có dữ liệu

    return num_rows, num_columns

filename = 'data.csv'  
rows, columns = count_rows_columns(filename)
print(f"Số hàng: {rows - 1}")
print(f"Số cột: {columns}")
