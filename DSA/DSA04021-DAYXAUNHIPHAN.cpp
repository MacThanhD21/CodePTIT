
/*

    Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:

    X[1] = “0”

    X[2] = “1”

    X[i] = X[i-2] + X[i-1] với i>2

    Với phép cộng (+) là phép nối hai xâu với nhau. 

    Cho hai số tự nhiên N và K (1<N<93; K đảm bảo trong phạm vi của xâu X[N]).

    Hãy xác định ký tự thứ K trong xâu X[N] là ký tự ‘0’ hay ký tự ‘1’.

Input:  
    Dòng 1 ghi số bộ test. 
    
    Mỗi bộ test ghi trên một dòng 2 số nguyên N và K.

Output: 

    Ghi ra màn hình kết quả tương ứng với từng bộ test.

Ví dụ:

Input               Output

2

3 1                 0

4 3                 1

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

string Find(ll n, ll k)
{
    if (n == 1)
        return "0";
    if (n == 2)
        return "1";

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


def fibo(n):
    F = [0] * (n + 1)
    F[1] = 1
    F[2] = 1
    for i in range(3, n + 1):
        F[i] = F[i - 1] + F[i - 2]
    return F

def find(n, k, F):
    if n == 1:
        return "0"
    if n == 2:
        return "1"

    if k <= F[n - 2]:
        return find(n - 2, k, F)
    else:
        return find(n - 1, k - F[n - 2], F)

t = int(input())
max_n = 93  # You can adjust this based on your requirements
F = fibo(max_n)

for _ in range(t):
    n, k = map(int, input().split())
    print(find(n, k, F))

*/