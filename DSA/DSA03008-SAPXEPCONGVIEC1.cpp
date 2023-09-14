
/*

    Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ 
    
    đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian kết thúc 
    
    của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động 
    
    được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào 
    
    số lượng hành động N; dòng tiếp theo đưa vào N số 
    
    Si tương ứng với thời gian bắt đầu mỗi hành động; 
    
    dòng cuối cùng đưa vào N số Fi tương ứng với thời gian 
    
    kết thúc mỗi hành động; các số được viết cách nhau một vài khoảng trống.

    T, N, Si, Fi thỏa mãn ràng buộc: 1≤T≤100;  1≤N, Fi, Si≤1000.

Output:

    Đưa số lượng lớn nhất các hành động có thể được thực thi bởi một máy hoặc một người.

Ví dụ:

Input                       Output

1

6                           4

1  3  0  5  8  5

2  4  6  7  9  9

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            p[i].fi = a[i];
            p[i].se = b[i];
        }
        sort(p, p + n, cmp);
        ll tmp = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].fi >= tmp)
            {
                ++ans;
                tmp = p[i].se;
            }
        }
        cout << ans << "\n";
    }
}