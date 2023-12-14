for _ in range(int(input())):
    N = input()
    print('NO' if sum(int(x) for x in N) % 10 != 0 or any(abs(int(N[i]) - int(N[i - 1])) != 2 for i in range(1, len(N))) else 'YES')