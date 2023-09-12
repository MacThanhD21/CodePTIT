

if __name__ == '__main__':
    T = int(input())  # Đọc số lượng bộ test

    for _ in range(T):
        N = int(input())  # Đọc số lượng giá trị ngẫu nhiên
        frequency = [0] * 1001  # Khởi tạo mảng frequency để đếm tần số xuất hiện

        for _ in range(N):
            value = int(input())
            frequency[value] += 1
        
        most_common = None
        max_frequency = 0
        
        for i in range(1, 1001):
            if frequency[i] > max_frequency:
                max_frequency = frequency[i]
                most_common = i

        print(most_common)
