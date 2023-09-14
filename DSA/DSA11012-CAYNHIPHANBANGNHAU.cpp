
/*

    Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem 
    
    cây nhị phân có giống nhau hay không?

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào 
    
    số N là số lượng cạnh của cây; dòng tiếp theo đưa vào 
    
    N bộ ba (u, v, x), trong đó u là node cha, v là node con, 
    
    x= R nếu v là con phải, x=L nếu v là con trái của mỗi cây; 
    
    u, v, x được viết cách nhau một vài khoảng trống.

    T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                   Output

2
2
1 2 L 1 3 R             1
2
1 2 L 1 3 R
2
1 2 L 1 3 R             0
2
1 3 L 1 2 R

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<string, int> mp;
        string tmp;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            string c;
            cin >> u >> v >> c;
            tmp = to_string(u) + to_string(v) + c;
            mp[tmp] = 1;
        }

        int m;
        cin >> m;
        bool ok = true;
        if (n != m)
        {
            ok = false;
        }
        string res;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            string c;
            cin >> u >> v >> c;
            res = to_string(u) + to_string(v) + c;

            if (mp[res] != 1)
            {
                ok = false;
                break;
                // cout << "0\n";
                // return 0;
            }
        }
        if (ok)
            cout << "1\n";
        else
            cout << "0\n";
    }
}