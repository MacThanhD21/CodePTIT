
/*

    Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong

    K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K =  101 là số BDN,

    k=102 không phải là số BDN.

    Số BDN của N là số P =M*N sao cho P là số BDN.

    Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.

    Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5*2=10.

    N = 17 ta tìm được số BDN của 17 là P = 653*17=11101.

Input:

    Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;

    T dòng kế tiếp mỗi dòng ghi lại một bộ Test.

    Mỗi test là một số tự nhiên N.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

3

2               10

12              11100

17              11101

*/

#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solve()
{
    queue<ll> Q;
    Q.push(1);
    ll res[105];
    vector<ll> v;
    while (1)
    {
        ll val = Q.front();
        Q.pop();
        if (val >= pow(2, 63))
        {
            break;
        }
        v.push_back(val);
        Q.push(val * 10);
        Q.push(val * 10 + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        for (auto x : v)
        {
            if (x % n == 0)
            {
                cout << x << "\n";
                break;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
}