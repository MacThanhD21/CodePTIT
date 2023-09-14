

def main():
	n = int(input())
	a = []
	cnt = 0
	while n:
		n -= 1
		s = input().split()
		if len(s) == 6 or len(s) == 8:
			a.append(" ".join(s))
		else:
			cnt += 1
			for x in a:
				print(x)
	print(cnt)
	

if __name__ == '__main__':
	main()