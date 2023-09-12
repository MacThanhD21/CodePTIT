def check(sequence):
    for x in sequence:
        if x not in "012":
            return False
    return True


if __name__ == "__main__":
    for _ in range(int(input())):
        s = input().strip()
        result = "YES" if check(s) else "NO"
        print(result)
