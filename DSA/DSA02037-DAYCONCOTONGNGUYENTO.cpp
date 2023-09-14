
/*

    Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. 
    
    Hãy liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.

    Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input

    Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

    Dòng đầu ghi số N (2 < N <15)

    Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, 
    
    nhỏ hơn 100 và khác nhau từng đôi một.
    
Output

    Với mỗi test, liệt kê tất cả các dãy con có tổng 
    
    các phần tử là số nguyên tố theo thứ tự từ điển tăng dần, 
    
    mỗi dãy con trên một dòng. 

Ví dụ

Input           Output

1

4

3 2 5 4         2

                3

                3 2

                4 3

                5

                5 2

                5 4 2

*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1005];
vector<vector<int>> v;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
}

bool prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void back(int i, int sum, vector<int> q)
{
    for (int j = 0; j <= 1; j++)
    {
        if (j)
            q.push_back(i);
        sum += a[i] * j;
        if (i == n && prime(sum))
        {
            v.push_back(q);
        }
        else if (i <= n)
        {
            back(i + 1, sum, q);
        }
        sum -= a[i] * j;
        if (j)
            q.pop_back();
    }
}
void solve()
{
    v.clear();
    init();

    vector<int> q;

    back(1, 0, q);

    for (auto it : v)
    {
        sort(it.begin(), it.end());
    }

    for (auto x : v)
    {
        for (auto i : x)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}