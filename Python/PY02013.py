

if __name__ == '__main__':
    def count_steps(n):
        steps = 0
        while n != 1:
            if n % 2 == 0:
                n = n // 2
            else:
                n = n * 3 + 1
            steps += 1
        return steps + 1  # Bổ sung 1 cho bước khi n = 1

    while True:
        n = int(input())
        if n == 0:
            break
        result = count_steps(n)
        print(result)
