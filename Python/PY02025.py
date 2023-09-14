

def main():
	n, m = list(map(int, input().split()))
	
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]

	A = []
	B = []
	
	Min, Max = 10**9, 0

	for x in a:
		if x not in A:
			Min = min(Min, x)
			Max = max(Max, x)
			A.append(x)
	for x in b:
		if x not in B:
			Min = min(Min, x)
			Max = max(Max, x)
			B.append(x)

	# print(Min, Max)

	for x in range(Min, Max + 1):
		if x in A and x in B:
			print(x, end = " ")
	print()

	for x in range(Min, Max + 1):
		if x in A and x not in B:
			print(x, end = " ")
	print()

	for x in range(Min, Max + 1):
		if x not in A and x in B:
			print(x, end = " ")
	print()

if __name__ == '__main__':
	main()

# 5 6
# 1 2 3 4 5
# 3 4 5 6 7 8