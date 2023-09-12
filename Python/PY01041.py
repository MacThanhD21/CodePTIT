
def is_increasing(s, idx):
    return all(int(s[i]) < int(s[i + 1]) for i in range(idx))

def is_decreasing(s, idx):
    return all(int(s[i]) > int(s[i + 1]) for i  in range(idx, len(s) - 1))

def is_bouncy(s):
    if len(s) < 3:
        return False
    for i in range(len(s) - 1):
        if is_increasing(s, i) and is_decreasing(s, i):
            return True
    return False

t = int(input())

for _ in range(t):
    N = input()
    result = "YES" if is_bouncy(N) else "NO"
    print(result)
