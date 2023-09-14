mod = 10**9 + 7


class Matrix:
    def __init__(self, a):
        self.a = a
        self.n = len(a)

    def __mul__(self, other):
        res = [[0 for _ in range(self.n)] for _ in range(self.n)]
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    res[i][j] += (self.a[i][k] * other.a[k][j]) % mod
                    res[i][j] %= mod
        return Matrix(res)


def Pow(a, k):
    if k == 1:
        return a

    tmp = Pow(a, k // 2)
    if k % 2 == 1:
        return tmp * tmp * a
    else:
        return tmp * tmp


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    u = []
    for i in range(n):
        row = list(map(int, input().split()))
        u.append(row)

    matrix_u = Matrix(u)
    q = Pow(matrix_u, k)

    for i in range(n):
        for j in range(n):
            print(q.a[i][j] % mod, end=" ")
        print()
