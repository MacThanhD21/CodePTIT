/*
    Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, 
    
    và X chỉ chứa hai chữ số 0 và 9.

Input: 
    Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). 
    
    Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

Output:  

    Với mỗi test in ra đáp án tìm được trên một dòng.

Ví dụ:

 
Input           Output

3               

2               90

5               90

11              99

*/

#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solution()
{
    queue<ll> Q;
    Q.push(9);
    vector<ll> v;
    ll res[505];
    while (1)
    {
        ll u = Q.front();
        Q.pop();
        if (u >= pow(2, 63))
            break;
        v.push_back(u);
        Q.push(u * 10);
        Q.push(u * 10 + 9);
    }
    for (int i = 1; i <= 500; i++)
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