#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    // cin.ignore();
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string c[100];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(c[i][0]) || isdigit(c[i][1]))
            {
                cout << c[i] << "\n";
                st.push(stoi(c[i]));
            }
            else if (c[i] == "+" || c[i] == "-" || c[i] == "*" || c[i] == "/")
            {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                if (c[i] == "+")
                    st.push(o2 + o1);
                if (c[i] == "-")
                    st.push(o2 - o1);
                if (c[i] == "*")
                    st.push(o2 * o1);
                if (c[i] == "/")
                    st.push(o2 / o1);
            }
        }
        cout << st.top() << "\n";
    }
}