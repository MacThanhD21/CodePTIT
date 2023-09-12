
if __name__ == '__main__':
    T = int(input())  # Đọc số lượng bộ test

    for _ in range(T):
        N = int(input())  # Đọc số lượng phần tử
        A = list(map(int, input().split()))  # Đọc dãy số
        
        frequency = {}  # Dùng để lưu tần số xuất hiện của từng số
        # print(type(frequency))
        max_frequency = 0  # Lưu tần số xuất hiện nhiều nhất
        most_common_number = None  # Lưu số có tần số xuất hiện nhiều nhất
        
        for num in A:
            if num in frequency:
                frequency[num] += 1
            else:
                frequency[num] = 1
            
            if frequency[num] > max_frequency:
                max_frequency = frequency[num]
                most_common_number = num
                
            # Kiểm tra nếu số có tần số xuất hiện lớn hơn N/2 thì in ra và kết thúc
            if max_frequency > N // 2:
                print(most_common_number)
                break
        else:
            # Nếu không tìm thấy số thỏa mãn, in ra "NO"
            print("NO")
