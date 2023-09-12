def is_palindrome(num_str):
    return num_str == num_str[::-1]

num_tests = int(input())

s = lambda x : is_palindrome(x) # Return True or False => x

for _ in range(num_tests):
    N = input().strip()
    Digit_Sum = sum(int(digit) for digit in N)
    ans = "YES" if len(str(Digit_Sum)) > 1 and s(str(Digit_Sum)) else "NO"
    print(ans)
