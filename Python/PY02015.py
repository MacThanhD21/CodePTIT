# cách 1
while True :
    a = [int(x) for x in input().split()]
    if a == [0, 0, 0, 0] : break
    cnt = 0
    while True :
        if a[0] == a[1] and a[1] == a[2] and a[2] == a[3] :
            print(cnt)
            break
        cnt += 1
        p = a[0]
        a[0] = abs(a[0] - a[1])
        a[1] = abs(a[1] - a[2])
        a[2] = abs(a[2] - a[3])
        a[3] = abs(a[3] - p)

# cách 2
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