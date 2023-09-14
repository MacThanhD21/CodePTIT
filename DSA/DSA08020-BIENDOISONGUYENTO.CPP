
/*

    Cho cặp số S và T là các số nguyên tố có 4 chữ số

    (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số).

    Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn

    đồng thời những điều kiện dưới đây:

    Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số

    ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);

    Số nhận được cũng là một số nguyên tố có 4 chữ số

    (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là

    không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);

    Số các bước dịch chuyển là ít nhất.

    Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành

    T = 8179 là 6 bao gồm các phép dịch chuyển như sau:

    8179 -> 8779 -> 3779 -> 3739 -> 3733 -> 1733 -> 1033.

Input:

    Dòng đầu tiên đưa vào số lượng test T (T≤100)

    Những dòng kế tiếp mỗi dòng đưa vào một test.

    Mỗi test là một bộ đôi S, T.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

2

1033 8179           6

1033 8779           5

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
int a[1000005];

void sang()
{
    for (int i = 0; i <= 1000000; i++)
    {
        a[i] = 1;
    }
    a[0] = a[1] = 0;
    for (int i = 2; i <= 1e3; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
                a[j] = 0;
        }
    }
}
bool used[100005];
void solve()
{
    memset(used, false, sizeof(used));
    string s, t;
    cin >> s >> t;
    queue<pair<string, int>> q;
    q.push({s, 0});
    used[stoi(s)] = true;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        auto u = x.first;
        auto w = x.second;
        if (u == t)
        {
            cout << w << endl;
            return;
        }
        for (int i = 0; i < u.size(); i++)
        {
            string tmp = u;
            for (int j = 0; j <= 9; j++)
            {
                tmp[i] = j + 48;
                if (stoi(tmp) >= 1000 && stoi(tmp) <= 9999 && !used[stoi(tmp)] && a[stoi(tmp)])
                    used[stoi(tmp)] = true, q.push({tmp, w + 1});
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    sang();
    while (t--)
        solve();
}
