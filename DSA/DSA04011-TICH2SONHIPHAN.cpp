
/*
    Cho hai xâu nhị phân biểu diễn hai số. Nhiệm vụ của bạn là đưa ra 
    
    tích của hai số. Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 hai xâu nhị phân S1, S2 
    
    được viết trên một dòng.

    T, S1, S2 thỏa mãn ràng buộc: 
    
    1≤T≤100;  1≤ length(S1), length(S2)≤30.

Output:

    Dưa ra tích của mỗi test theo từng dòng.
    
Ví dụ:

Input           Output

2
1100 01         12
01 01           1


*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    string a, b;
    cin >> a >> b;
    ll x = 0, y = 0;
    ll mul = 1;
    for (ll i = a.size() - 1; i >= 0; i--)
    {
        x += (a[i] - 48) * mul;
        mul *= 2;
    }
    ll mul2 = 1;
    for (ll i = b.size() - 1; i >= 0; i--)
    {
        y += (b[i] - 48) * mul2;
        mul2 *= 2;
    }
    cout << x * y << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
