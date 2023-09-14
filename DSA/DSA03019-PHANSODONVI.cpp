
/*

    Một phân số đơn vị nếu tử số của phân số đó là 1.

    Mọi phân số nguyên dương đều có thể biểu diễn thành

    tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6.

    Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn

    phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là bộ đôi tử số P và mẫu số Q của

    phân số nguyên dương được viết trên một dòng.

    T, P, Q thỏa mãn ràng buộc: 1≤T≤100;  1≤P, Q≤100.

Output:

    Đưa ra đáp án tìm được trên 1 dòng, theo dạng “1/a + 1/b + …”

Ví dụ:

Input               Output

2

2 3                 1/2 + 1/6

1 3                 1/3


*/

/*
 * MT677
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int mod = 1e9 + 7;
const int mnX = 1e7 + 5;

void egyptian(ll tu, ll mau)
{
    if (mau % tu == 0)
    {
        cout << 1 << "/" << mau / tu;
        return;
    }
    else
    {
        ll tmp = mau / tu + 1;
        cout << 1 << "/" << tmp << " + ";
        egyptian(tu * tmp - mau, tmp * mau);
    }
}

void solve()
{
    ll tu, mau;
    cin >> tu >> mau;
    egyptian(tu, mau);
}
int main()
{
    IO();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
        cout << "\n";
    }
}