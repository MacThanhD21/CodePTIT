
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        s = input()
        if s[0] == s[-1]:
            print('YES')
        else:
            print('NO')

