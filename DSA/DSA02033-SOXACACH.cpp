
/*

    Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được 

    gọi là số xa cách nếu thỏa mãn:

        + K không chứa chữ số 0

        + Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần

        + Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1. 

        + Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

Input

    Dòng đầu ghi số bộ test (không quá 10)

    Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)
    
Output

    Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.

    Sau mỗi test in ra một khoảng trống.

Ví dụ

Input           Output

2

3               2413

4               3142

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ant(char x, char y)
{
    return abs((x - '0') - (y - '0')) == 1;
}

bool check(string s)
{
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (ant(s[i], s[i - 1]) || ant(s[i + 1], s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        vector<string> v;
        do
        {
            v.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        for (string x : v)
        {
            if (check(x))
                cout << x << "\n";
        }
    }
}