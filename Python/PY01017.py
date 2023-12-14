def encode_string(s):
    encoded = ""
    count = 1
    
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
        else:
            print(count, s[i - 1], sep='', end='')
            count = 1
    print(count, s[-1], sep='', end='')
if __name__ == "__main__":
    num_tests = int(input())
    
    for _ in range(num_tests):
        s = input()
        encode_string(s)
        print()