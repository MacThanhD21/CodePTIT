
def rotate(s):
    x = sum(ord(c) - ord('A') for c in s) % 26
    rotated = ""
    for c in s:
        rotated += chr((ord(c) - ord('A') + x) % 26 + ord('A'))
    return rotated
def merge(s1, s2):
    merged = ""
    for c1, c2 in zip(s1, s2):
        x = ord(c2) - ord('A')
        merged += chr((ord(c1) - ord('A') + x) % 26 + ord('A'))
    return merged

for _ in range(int(input())):
    s = input()
    half = len(s) // 2
    res_1 = rotate(s[:half])
    res_2 = rotate(s[half:])
    ans = merge(res_1, res_2)
    print(ans)    
    
    