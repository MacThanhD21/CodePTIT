
#include <bits/stdc++.h>

using namespace std;

// ((())) : 123321
void solve(string s, int n)
{
    int l = 1;
    stack<int> r;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            cout << l << " ";

            r.push(l);

            l++;
        }
        else if (s[i] == ')')
        {
            cout << r.top() << " ";
            r.pop();
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        int n = s.size();
        solve(s, n);
        cout << "\n";
    }
}
