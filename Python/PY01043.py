def is_palindrome(num):
    return str(num) == str(num)[::-1]

def all_even_digits(num):
    return all(int(digit) % 2 == 0 for digit in str(num))

def list_numbers(N):
    results = []
    start = 22 if N > 22 else N
    if start % 2 == 1:
        start += 1
    for i in range(start, N, 2):
        if is_palindrome(i) and all_even_digits(i) and (len(str(i)) % 2 == 0):
            results.append(i)
    return results

num_tests = int(input())

for _ in range(num_tests):
    N = int(input())
    result = list_numbers(N)
    print(*result)