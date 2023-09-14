
/*

    Có n tờ tiền có giá trị t[1], t[2], …, t[n].

    Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S

    Chú ý: Các tờ tiền có giá trị bất kỳ và có thể bằng nhau, 
    
    mỗi tờ tiền chỉ được dùng một lần.

Input

    Mỗi bộ test gồm 2 số nguyên n và S (n ≤ 30; S  ≤  109).

    Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: 

    Ghi ra trên một dòng số tờ tiền ít nhất phải trả.

    Nếu không thể tìm được kết quả, in ra -1.

Ví dụ

Input           Output

3 5

1 4 5           1

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, S;
int a[100];
int ans = 1e9;

void back(int pre, int sum, int cnt)
{
    for (int j = pre + 1; j <= n; j++)
    {
        sum += a[j];
        if (sum == S)
        {
            cnt++;
            ans = min(ans, cnt);
        }
        else if (sum < S)
        {
            back(j, sum, cnt);
        }
        sum -= a[j];
    }
}

void solve()
{
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    back(0, 0, 0);
    cout << ans << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}