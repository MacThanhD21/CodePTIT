

if __name__ == '__main__':
     # Đọc số lượng phần tử
    N = int(input()) 
    # Đọc dãy số và chuyển thành tập hợp để loại bỏ các số trùng lặp
    A = set(map(int, input().split()))  

    # Tìm số nhỏ nhất còn thiếu bằng cách duyệt từ 1 đến N + 1
    # Nếu tất cả các số từ 1 => N đều thỏa mãn thì nhảy sang N + 1
    missing_number = None
    for i in range(1, N+2):
        if i not in A:
            missing_number = i
            break

    print(missing_number)
