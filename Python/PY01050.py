import itertools

# Note

def is_valid(s):
    return s.count('A') <= s.count('B') and s.count('B') <= s.count('C')


def is_valid2(s):
    if 'A' in s and 'B' in s and 'C' in s:
        return True
    else:
        return False


if __name__ == '__main__':
    N = int(input())

    characters = ['A', 'B', 'C']

    for length in range(1, N + 1):
        # Tạo tất cả các xâu có độ dài length bằng cách chọn từ characters
        all_strings = itertools.product(characters, repeat=length)

        for string in all_strings:
            s = ''.join(string)
            if is_valid(s) and is_valid2(s):
                print(s)
