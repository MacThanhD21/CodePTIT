

def is_pivot(arr, i):
    print(i)
    left_max = max(arr[:i], default=0)
    right_min = min(arr[i + 1:], default=100000000)
    return arr[i] >= left_max and arr[i] <= right_min

if __name__ == '__main__':

	n = int(input())
	a = [int(x) for x in input().split()]

	ans = 0
	for i in range(n):
		if is_pivot(a, i): ans += 1
	print(ans)