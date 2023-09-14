/*

    Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như 
    
    một bộ đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian 
    
    kết thúc của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất
    
    các hành động được thực hiện bởi một máy hoặc một người sao cho hệ 
    
    không xảy ra mâu thuẫn.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa 
    
    vào số lượng hành động N; dòng tiếp theo đưa vào N 
    
    số Si tương ứng với thời gian bắt đầu mỗi hành động; 
    
    dòng cuối cùng đưa vào N số Fi tương ứng với thời gian 
    
    kết thúc mỗi hành động; các số được viết cách nhau một vài khoảng trống.

    T, N, Si, Fi thỏa mãn ràng buộc: 1≤T≤100;  1≤N, Fi, Si≤1000.

Output:

    Đưa số lượng lớn nhất các hành động có thể 
    
    được thực thi bởi một máy hoặc một người.
    
Ví dụ:

Input                       Output

1

6                           4

1  3  0  5  8  5

2  4  6  7  9  9

*/

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
#define ll long long

void solve()
{
    int n;
    cin >> n;
    pair<int, ii> a[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].fi = x;
        a[i].se.fi = y;
        a[i].se.se = z;
    }

    sort(a + 1, a + n + 1, [](pair<int, ii> x, pair<int, ii> y)
         { return x.se.se > y.se.se; });

    bool used[1005] = {false}; // đánh dấu mốc thời gian đã được thực hiện

    int Job = 0;   // số lượng công việc tối đa có thể thực hiện được
    ll Profit = 0; // lợi nhuận tối đa thu được

    for (int i = 0; i < n; i++)
    {
        // 0 1 2 3 ...
        //  duyệt qua các mốc công việc còn trống
        for (int j = a[i].se.fi - 1; j >= 0; j--)
        {
            if (used[j] == false)
            {
                Job++;
                Profit += a[i].se.se;
                used[j] = true;
                break;
            }
        }
    }

    cout << Job << " " << Profit << "\n";
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}