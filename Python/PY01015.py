def is_non_decreasing(number):
    number_str = str(number)
    n = len(number_str)
    for i in range(n - 1):
        if int(number_str[i]) > int(number_str[i + 1]):
            return False
    return True

if __name__ == "__main__":
    num_tests = int(input())
    
    for _ in range(num_tests):
        num = int(input())
        if is_non_decreasing(num):
            print("YES")
        else:
            print("NO")
