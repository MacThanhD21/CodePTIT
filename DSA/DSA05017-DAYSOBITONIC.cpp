
/*

    Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.
    Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 0≤A[i] ≤100.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input                           Output

2
6
80 60 30 40 20 10               210
9
1 15 51 45 33 100 12 18 9       194

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int Bito1[n + 1] = {0}, Bito2[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        Bito1[i] = a[i];
        for (int j = 1; j <= i; j++)
        {
            if (a[i] > a[j])
            {
                Bito1[i] = max(Bito1[i], Bito1[j] + a[i]);
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        Bito2[i] = a[i];
        for (int j = n; j >= i; j--)
        {
            if (a[i] > a[j])
            {
                Bito2[i] = max(Bito2[i], Bito2[j] + a[i]);
            }
        }
    }
    // for(auto x : Bito1) cout << x << " "; cout << "\n";
    // for(auto x : Bito2) cout << x << " "; cout << "\n";

    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, 1ll * Bito1[i] + Bito2[i] - a[i]);
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}