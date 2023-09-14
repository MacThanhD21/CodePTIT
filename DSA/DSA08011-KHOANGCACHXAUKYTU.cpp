

/*

    Cho tập n xâu ký tự S và hai xâu s, t Î S. Ta giả thiết các xâu ký tự 
    
    S[i] Î S có độ dài bằng nhau.  Hãy tìm khoảng cách đường đi 
    
    ngắn nhất từ s đến t. Biết từ một xâu ký tự bất kỳ ta chỉ được 
    
    phép dịch chuyển đến xâu khác với nó duy nhất 1 ký tự. Ví dụ 
    
    ta có tập các từ S = { POON, TOON, PLEE, SAME, POIE, PLEA, PLIE, POIN }, 
    
    s = TOON, t = PLEA ta có độ dài đường đi ngắn nhất là 7 tương ứng với 
    
    các phép dịch chuyển : TOON -> POON –> POIN –> POIE –> PLIE –> PLEE –> PLEA.

Input:

    Dòng đầu tiên đưa vào số lượng test T (T≤100).

    Mỗi test được tổ chức thành 2 dòng. 
    
    Dòng thứ nhất ghi lại n là số từ trong S và hai từ s, t.  
    
    Dòng thứ 2 đưa vào n xâu xâu ký tự của S; 
    
    các xâu ký tự được viết cách nhau một vài khoảng trống, 
    
    có độ dài không vượt quá 10 kí tự.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input                                               Output

1

8 TOON  PLEA

POON TOON PLEE SAME  POIE  PLEA  PLIE  POIN         7

*/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string S[n];
    unordered_set<string> se;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        if(S[i] != s);
            se.insert(S[i]);
    }
    queue<pair<string, int>> Q;
    Q.push({s, 1});
    se.erase(s);
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        string u = top.fi;
        int step = top.se;

        if (u == t)
        {
            cout << step << "\n";
            return;
        }
        for (int i = 0; i < u.size(); i++)
        {
            char x = u[i];
            for (auto j = 'A'; j <= 'Z'; j++)
            {
                u[i] = j;
                cout << u << "\n";
                if(u == t){
                    cout << step + 1 << "\n";
                    return;
                }
                if (se.find(u) != se.end())
                {
                    Q.push({u, step + 1});
                    se.erase(u);
                }
                u[i] = x;
            }
        }
    }
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}