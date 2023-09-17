def count_ways_to_represent_N(N):
    count = 0
    start = 1
    while start <= N // 2 + 1:
        total = 0
        current = start
        while total < N:
            total += current
            current += 1
        if total == N:
            count += 1
        start += 1
    return count

num_tests = int(input())
results = []

for _ in range(num_tests):
    N = int(input())
    ways = count_ways_to_represent_N(N)
    results.append(ways)

for ways in results:
    print(ways)
