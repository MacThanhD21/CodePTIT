
/*

    Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất 
    
    được tạo bởi số 9 và số 0 chia hết cho N. 
    
    Ví dụ với N = 5 ta sẽ tìm ra  X = 90.

Input:

    Dòng đầu tiên ghi lại số lượng test T (T≤100).

    Những dòng kế tiếp mỗi dòng ghi lại một test. 
    
    Mỗi test là một số tự nhiên N được ghi trên một dòng (N≤100).
Output:

    Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được .

Ví dụ:

Input               Output

2

5                   90

7                   9009

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solution()
{
    queue<ll> Q;
    Q.push(9);
    vector<ll> v;
    ll res[201];
    while (1)
    {
        ll u = Q.front();
        v.push_back(u);
        if (u >= 1e18)
            break;
        Q.pop();
        Q.push(u * 10);
        Q.push(u * 10 + 9);
    }
    for (int i = 1; i <= 200; i++)
    {
        for (auto it : v)
        {
            if (it % i == 0)
            {
                res[i] = it;
                break;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        cout << res[n] << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solution();
}