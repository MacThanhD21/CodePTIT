s = input()

# Tất cả các số 6, 68, 688 khi kết hợp lại với nhau không bao h tạo ra 3 số 8 liên tiếp

if s.startswith('6') and '888' not in s and all(x == '6' or x == '8' for x in s):
    print("YES")
else:
    print("NO")
