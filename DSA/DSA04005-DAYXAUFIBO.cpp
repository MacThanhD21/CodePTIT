
/*

    Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là

    dãy xâu Fibonacci nếu thỏa mãn tính chất:

    G(1) = A; G(2) = B; G(n) = G(n-2) + G(n-1). Với phép cộng (+)

    là phép nối hai xâu với nhau.  Bài toán đặt ra là tìm ký tự ở vị trí

    thứ i (tính từ 1) của xâu Fibonacci thứ n.

Dữ liệu vào:

    Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và i (1<N<93).

    Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số.

Kết quả:

    Ghi ra màn hình kết quả tương ứng với từng bộ test.

Input       Output

2

6 4         A

8 19        B

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll F[93];

void fibo()
{
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 93; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
}

char Find(ll n, ll k)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';

    if (k <= F[n - 2])
    {
        return Find(n - 2, k);
    }
    else
    {
        return Find(n - 1, k - F[n - 2]);
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    fibo();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k;
        cin >> n >> k;
        cout << Find(n, k) << "\n";
    }
}


/*

F = [0] * 94  # Initialize an array to store Fibonacci numbers

def fibo():
    F[1] = 1
    F[2] = 1
    for i in range(3, 94):
        F[i] = F[i - 1] + F[i - 2]

def find(n, k):
    if n == 1:
        return 'A'
    if n == 2:
        return 'B'

    if k <= F[n - 2]:
        return find(n - 2, k)
    else:
        return find(n - 1, k - F[n - 2])

if __name__ == "__main__":
    fibo()
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        print(find(n, k))

*/