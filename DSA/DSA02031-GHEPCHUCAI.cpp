/*

    Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm 
    
    là ‘A’, ‘E’, còn lại là phụ âm.

    Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c 
    
    (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả 
    
    không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.

    Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Input

    Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

Output

    Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

Ví dụ

Input           Output

D               ABCD

                ABDC

                ACBD

                ACDB

                ADBC

                ADCB

                BCDA

                BDCA

                CBDA

                CDBA

                DBCA

                DCBA

*/


#include <bits/stdc++.h>

using namespace std;

int n;
char M[1005], u;
bool vis[1005];

bool N_am(char x)
{
    return x == 'A' || x == 'E';
}

bool check()
{
    for (int i = 2; i <= n - 1; i++)
    {
        if (!N_am(M[i - 1]) && N_am(M[i]) && !N_am(M[i + 1]))
            return false;
    }
    return true;
}

void Back(int i)
{
    for (char j = 'A'; j <= u; j++)
    {
        if (!vis[j])
        {
            M[i] = j;
            vis[j] = true;
            if (i == n)
            {
                if (check())
                {
                    for (int i = 1; i <= n; i++)
                    {
                        cout << M[i];
                    }
                    cout << "\n";
                }
            }
            else
            {
                Back(i + 1);
            }
            vis[j] = false;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> u;
        n = u - 'A' + 1;
        Back(1);
    }
}
