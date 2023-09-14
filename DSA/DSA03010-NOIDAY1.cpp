/*

    Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. 
    
    Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí 
    
    ối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j 
    
    là tổng độ dài hai sợi dây A[i] và A[j].

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất 
    
    đưa vào số lượng sợi dây N; dòng tiếp theo đưa vào 
    
    N số A[i] là độ dài của các sợi dây; các số được 
    
    viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;1≤N≤106; 0≤A[i]≤106.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
    
Ví dụ:

Input               Output

2
4                   29
4 3 2 6
5                   69
4 2 7 6 9

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define quick()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
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
        ll q3 = q1 + q2;
        ans += q3;
        Q.push(q3);
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}