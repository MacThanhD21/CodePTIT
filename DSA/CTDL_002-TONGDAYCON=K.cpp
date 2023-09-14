/*

    Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. 

    Hãy viết chương trình liệt kê tất cả các dãy con của dãy số 

    A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K. 

    Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:

    5        50       

    5        10        15       20           25   

    Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

    Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết 

    cách nhau bởi một  khoảng trống.

    Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.

           10                    15                    25

           5                      20                    25

           5                      10                    15                    20

           3
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pii pair<int, int>
#define vi vector<int>
#define ft first
#define sd second

int n, k, a[1001], x[1001];
vector<vi> ans;

void inp()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Try(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        x[i] = j;
        if (i == n)
        {
            int sum = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (x[i])
                    sum += a[i];
            }
            if (sum == k)
            {
                vector<int> tmp;
                for (int i = 1; i <= n; ++i)
                {
                    if (x[i])
                        tmp.push_back(a[i]);
                }
                ans.push_back(tmp);
            }
        }
        else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    Try(1);
    sort(begin(ans), end(ans), greater<vi>());
    for (auto it : ans)
    {
        for (int x : it)
            cout << x << " ";
        cout << "\n";
    }
    cout << ans.size() << "\n";
}