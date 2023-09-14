

/*

    HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều, 
    
    trên mỗi miếng ghép được điền một số nguyên, có 8 miếng được điền số  
    
    từ 1 đến 8 và có hai miếng điền số 0. Các miếng liên kết với nhau tạo 
    
    thành lưới tổ ong. Ban đầu các miếng ghép ở vị trí như hình vẽ. Tại mỗi bước, 
    
    chọn một miếng ghép có đúng 6 miếng ghép kề cạnh làm tâm, rồi xoay một 
    
    nấc 6 miếng ghép kề cạnh đó theo chiều kim đồng hồ. Như vậy 
    
    cách chọn tâm, đó là chọn tâm bên trái và chọn tâm bên phải.

    C:\Users\ADMIN\Downloads\download (1).png

Yêu cầu: 

    Cho một trạng thái của trò chơi 
    
    (nhận được sau một dãy biến đổi từ trạng thái ban đầu), 
    
    hãy tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu.

Input:

    Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:

    Dòng đầu tiên chứa 3 số ở 3 miếng ghép dòng thứ nhất (thứ tự từ trái qua phải).

    Dòng thứ hai chứa 4 số ở 4 miếng ghép dòng thứ hai (thứ tự từ trái qua phải).

    Dòng thứ 3 chứa 3 số ở 3 miếng ghép dòng thứ ba (thứ tự từ trái qua phải).

Output: 

    Với mỗi bộ test in ra một số nguyên là số phép biến đổi 
    
    ít nhất để đưa được về trạng thái ban đầu.
 

Ví dụ:

Input               Output

1

1 0 2

8 6 0 3             5

7 5 4

*/

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

inline string Change(string &s, int a[])
{
    string res = "";
    for (int i = 0; i < 10; ++i)
        res += s[a[i]];
    return res;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while (t--)
    {
        unordered_map<string, int> m;
        int ans = 1e9;
        string a, b = "1238004765";
        for (int i = 0; i < 10; ++i)
        {
            int x;
            cin >> x;
            a += to_string(x);
        }
        queue<pair<string, int>> q1, q2;
        q1.push({a, 0});
        q2.push({b, 0});
        pair<string, int> top;
        while (q1.size())
        {
            top = q1.front();
            q1.pop();
            pair<string, int> tmp = {Change(top.fi, l1), top.se + 1};
            if (!m[tmp.fi])
            {
                m[tmp.fi] = tmp.se;
                q1.push(tmp);
            }
            tmp.fi = Change(top.fi, r1);
            if (!m[tmp.fi])
            {
                m[tmp.fi] = tmp.se;
                q1.push(tmp);
            }
            if (tmp.se == 14)
                break;
        }
        while (q2.size())
        {
            top = q2.front();
            q2.pop();
            if (m[top.fi])
                ans = min(ans, m[top.fi] + top.se);
            pair<string, int> tmp = {Change(top.fi, l2), top.se + 1};
            q2.push(tmp);
            tmp.fi = Change(top.fi, r2);
            q2.push(tmp);
            if (tmp.se == 14)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}