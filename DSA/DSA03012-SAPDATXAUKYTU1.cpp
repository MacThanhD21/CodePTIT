/*

    Cho xâu ký tự S bao gồm các ký tự in thường. Nhiệm vụ của bạn là kiểm tra
    
    xem ta có thể sắp đặt lại các ký tự trong S để hai ký tự giống nhau đều không
    
     kề nhau hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn
     
    yêu cầu bài toán, ngược lại đưa ra -1.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một xâu ký tự S được viết trên một dòng.

    T, S thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

3
geeksforgeeks       1
bbbabaaacd          1
bbbbb               -1

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define quick()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define FOR0(i, a, b) for (int i = a; i < b; i++)
#define FOR1(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

map<char, ll> mp;

void solve()
{
    string s;
    cin >> s;
    for (char x : s)
    {
        mp[x]++;
    }
    ll freMax = 0;
    for (auto it : mp)
    {
        freMax = max(freMax, it.se);
    }
    if (freMax <= (int)s.size() + 1 - freMax)
        cout << "1\n";
    else
        cout << "-1\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}