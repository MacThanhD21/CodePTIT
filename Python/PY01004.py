

def main():
    for _ in range(int(input())):
        n = int(input())
        
        rem = ""
        
        while n >= 10:
            r = n % 10
            n //= 10
            if r < 5:
                rem = "0" + rem
            else:
                rem = "0" + rem
                n += 1
        # Xử lý cả 2 trường hợp:
            # Nếu n < 10: thì n vẫn giữ nguyên và + rem rỗng
            # Nếu n >= 10: thì n bị chia về còn 1 số và + với chuỗi rem "0"
            
        print(str(n) + rem)

if __name__ == '__main__':
    main()