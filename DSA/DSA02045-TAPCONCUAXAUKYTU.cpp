
/*

    Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con 
    
    của xâu ký tự S theo thứ tự từ điển.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.

    T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

1
3
abc             a ab abc ac b bc c

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
string s;

void back(int pre, int n, vector<int> res)
{
    for (int j = pre + 1; j <= n; j++)
    {
        res.push_back(j);
        for (auto x : res)
            cout << s[x];
        cout << " ";
        back(j, n, res);
        res.pop_back();
    }
}

void solve()
{
    cin >> n >> s;
    s = "@" + s;
    vector<int> res;
    back(0, n, res);
    cout << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}