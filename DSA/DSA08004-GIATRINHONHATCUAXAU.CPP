
/*


    Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z].

    Ta định nghĩa giá trị của xâu S[] là tổng bình phương

    số lần xuất hiện mỗi ký tự trong xâu. Ví dụ với

    xâu S[] = “AAABBCD” ta có F(S) = 32 + 22 + 12 + 12 = 15.

    Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.

Input:

    Dòng đầu tiên đưa vào số lượng test T (T≤100).

    Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất

    ghi lại số K. Dòng thứ 2 ghi lại xâu ký tự S[]

    có độ dài không vượt quá 10^6.

Output:

    Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.

Input                   Output

2

0

ABCC                    6

1

ABCC                    3

*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define ll long long

void solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    map<char, ll> mp;

    for (auto x : s)
    {
        mp[x]++;
    }
    priority_queue<ll> Q;
    for (auto it : mp)
    {
        Q.push(it.second);
    }
    while (k--)
    {
        auto top = Q.top();
        Q.pop();
        --top;
        Q.push(top);
        if (top < 0)
            Q.push(0);
        //		Q.push(max(top, 1ll * 0));
    }
    ll ans = 0;
    while (Q.size())
    {
        ll top = Q.top();
        Q.pop();
        ans += 1ll * top * top;
    }
    cout << ans << "\n";
}

int main()
{
    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
}