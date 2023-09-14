/*
    Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và 

    số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều 

    không quá 100, K không quá 104). Hãy viết chương trình lấy mỗi hàng, mỗi cột 

    duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.

INPUT: 
    Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C. 

OUTPUT:
    Dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách 
    
    theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn. 

Ví dụ:

INPUT           OUTPUT

3 10

2 4 3           2

1 3 6           1 3 2

4 2 4           3 2 1

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, k, a[N][N];

vector<vector<int>> v;
bool used[N];

void init()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(used, false, sizeof(used));
    v.clear();
}

void back(int i, int sum, vector<int> q)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = true;
            q.push_back(j);
            sum += a[i][j];

            if (sum == k && i == n)
                v.push_back(q);
            else
                back(i + 1, sum, q);

            used[j] = false;
            sum -= a[i][j];
            q.pop_back();
        }
    }
}

void solve()
{
    init();
    vector<int> q;
    back(1, 0, q);
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}