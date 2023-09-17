

if __name__ == '__main__':
	for _ in range(int(input())):
		n, p = [int(x) for x in input().split()]

		ans = 0
		x = 1

		while n / (p ** x) > 1:
			ans += int(n / (p ** x))
			x += 1
		print(ans)