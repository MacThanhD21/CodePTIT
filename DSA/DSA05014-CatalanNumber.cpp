/*

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
string add(string a, string b)
{
    int mis = 0;
    string res = "";
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 && j >= 0)
    {
        int x = a[i] - '0' + b[j] - '0' + mis;
        mis = x / 10;
        res += to_string(x % 10);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int x = a[i] - '0' + mis;
        mis = x / 10;
        res += to_string(x % 10);
        i--;
    }
    while (j >= 0)
    {
        int x = b[j] - '0' + mis;
        mis = x / 10;
        res += to_string(x % 10);
        j--;
    }
    if (mis == 1)
        res = res + "1";
    reverse(res.begin(), res.end());
    return res;
}
string multi(string a, string b)
{
    int cnt = 0;
    vector<string> v;
    string res = "0";
    for (int i = a.size() - 1; i >= 0; i--)
    {
        string s = "";
        for (int j = 0; j < cnt; j++)
        {
            s += "0";
        }
        cnt++;
        int mis = 0;
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int x = (a[i] - '0') * (b[j] - '0') + mis;
            s = s + to_string(x % 10);
            x /= 10;
            mis = x;
        }
        if (mis != 0)
            s = s + to_string(mis);
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    for (string x : v)
    {
        res = add(res, x);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string c[n + 1];
        c[0] = "1";
        for (int i = 1; i <= n; i++)
        {
            c[i] = "0";
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                c[i] = add(c[i], multi(c[j], c[i - j - 1]));
            }
        }
        cout << c[n] << endl;
    }
}
