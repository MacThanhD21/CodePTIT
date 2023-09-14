
/*
    Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. 
    
    Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng 
    
    chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ 
    
    i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

Input

    Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. 
    
    Dòng đầu tiên là số nguyên N (N ≤ 2*106).

    Dòng tiếp theo gồm N số nguyên dương c[i] ( 1 ≤ A[i] ≤ 109).

Output

    In ra đáp án của bộ test trên từng dòng, theo modulo 109+7.

Ví dụ:

Input:                  Output

1

7                       59
2 4 1 2 10 2 3


*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

void solve()
{
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    // top auto min;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        Q.push(x);
    }
    ll ans = 0;
    while (Q.size() != 1)
    {
        ll q1 = Q.top();
        Q.pop();
        ll q2 = Q.top();
        Q.pop();
        ll q3 = ((q1 % mod) + (q2 % mod)) % mod;
        ans = ((ans % mod) + (q3 % mod)) % mod;
        Q.push(q3);
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}