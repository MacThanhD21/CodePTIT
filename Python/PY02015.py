

if __name__ == '__main__':
    def transform_array(arr):
        return [abs(arr[i] - arr[(i + 1) % 4]) for i in range(4)]

    def all_equal(arr):
        return all(x == arr[0] for x in arr)

    while True:
        A = list(map(int, input().split()))
        if A == [0, 0, 0, 0]:
            break

        steps = 0
        while not all_equal(A):
            A = transform_array(A)
            steps += 1

        print(steps)
