
/*

    Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số K nhỏ nhất,

    sao cho K có đúng N ước. Input đảm bảo rằng đáp án không vượt quá 10^18.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤  20).

    Mỗi test gồm 1 số nguyên N ( 1 ≤  N ≤  1000).

Output:

    Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input           Output

2

4               6

6               12

*/

// https://code.ptit.edu.vn/student/question/DSA02020
// SỐ NHỎ NHẤT CÓ N ƯỚC SỐ

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll INF = 1e19 + 1;

ll f[15][1111];
vector<ll> p[15];

void Prepare()
{
    ll a[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int i = 1; i <= 11; i = i + 1)
    {
        p[i].push_back(1);
        p[i].push_back(a[i]);
        while (p[i][p[i].size() - 1] > p[i][p[i].size() - 2])
        {
            int k = p[i].size() - 1;
            p[i].push_back(p[i][k] * a[i]);
        }
    }
}

void TestCase()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i = i + 1)
    {
        if (i - 1 >= p[1].size() - 1)
            f[1][i] = INF;
        else
            f[1][i] = p[1][i - 1];
    }
    for (int i = 2; i <= 11; i = i + 1)
    {
        for (int j = 1; j <= n; j = j + 1)
        {
            f[i][j] = INF;
            for (int k = 1; k <= j; k = k + 1)
                if (j % k == 0)
                    if ((k - 1 < p[i].size() - 1) && (f[i - 1][j / k] < INF))
                        if ((f[i - 1][j / k] * p[i][k - 1]) % f[i - 1][j / k] == 0)
                            if (f[i][j] > f[i - 1][j / k] * p[i][k - 1])
                                f[i][j] = f[i - 1][j / k] * p[i][k - 1];
        }
    }
    cout << f[11][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Prepare();
    int T = 1;
    cin >> T;
    while (T--)
    {
        TestCase();
        cout << endl;
    }
    return 0;
}