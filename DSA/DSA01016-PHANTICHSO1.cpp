/*
    Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách 
    
    phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. 
    
    Phép hoán vị vủa một cách được xem là giống nhau. Ví dụ với N = 5 ta có 
    
    kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một số tự nhiên N được viết trên một dòng.

    T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.


Input               Output

2

4                   (4) (3 1) (2 2) (2 1 1) (1 1 1 1)

5                   (5) (4 1)  (3 2)  (3 1 1) (2 2 1)  (2 1 1 1)  (1 1 1 1 1)


*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

int tar;

void ou(vector<int> s)
{
    cout << "(";
    for (int i = 0; i < s.size() - 1; i++)
    {
        cout << s[i] << " ";
    }
    cout << s[s.size() - 1] << ") ";
}

void back(int n, vector<int> s, int sumpre)
{
    for (int i = n; i >= 1; i--)
    {
        s.push_back(i);

        if (sumpre + i == tar)
            ou(s);

        else if (sumpre + i < tar)
            back(i, s, sumpre + i);

        s.pop_back();
    }
}

void solve()
{

    cin >> tar;
    // string s = "";
    vector<int> v;
    back(tar, v, 0);
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}