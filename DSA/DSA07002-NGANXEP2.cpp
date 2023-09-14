
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define quick()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

void solution()
{
    int q;
    cin >> q;
    stack<int> st;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "PUSH")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        if (s == "POP")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        if (s == "PRINT")
        {
            if (st.empty())
            {
                cout << "NONE\n";
            }
            else
                cout << st.top() << "\n";
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solution();
    }
}