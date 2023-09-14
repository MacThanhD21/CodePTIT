/*

    Cho xâu ký tự S bao gồm các ký tự và số D. Nhiệm vụ của bạn là kiểm tra

    xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau

    đều có khoảng cách là D hay không? Đưa ra 1 nếu có thể sắp đặt lại các ký tự

    trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test gồm hai dòng: dòng thứ nhất là số D;

    dòng tiếp theo là xâu S.

    T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤D≤100.
    
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

2
2               1
ABB

2               -1
AAA

*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int d;
    cin >> d;
    string s;
    cin >> s;
    int mp[26] = {0};
    for (char x : s)
    {
        mp[x - 'A']++;
    }
    int freMax = 0;
    for (int i = 0; i < 26; i++)
    {
        freMax = max(freMax, mp[i]);
    }
    int emptyArea = s.size() / d + 1;
    if (freMax <= emptyArea)
        cout << "1\n";
    else
        cout << "-1\n";
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