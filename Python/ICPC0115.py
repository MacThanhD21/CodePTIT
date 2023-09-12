def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

def check(num):
    digit_factorial_sum = 0
    original_num = num
    
    while num > 0:
        digit = num % 10
        digit_factorial_sum += factorial(digit)
        num //= 10
    
    return digit_factorial_sum == original_num

T = int(input())

for _ in range(T):
    N = int(input())
    if check(N):
        print("Yes")
    else:
        print("No")
