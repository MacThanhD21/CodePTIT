

/*

    Cho dãy số a[] có n phần tử, đánh số từ 1 đến n. 
    
    Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần, 
    
    các phần tử ở vị trí chẵn theo thứ tự giảm dần.

Input

    Dòng đầu tiên ghi số n, không quá 105

    Dòng thứ 2 ghi n số của dãy a[] (a ≤ a[i] ≤ 109)

Output

    Ghi ra dãy số kết quả trên một dòng

Ví dụ

Input               Output

4

1 2 3 4             1 4 3 2

*/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> chan, le;
    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i += 2)
        le.pb(a[i]);
    for (int i = 1; i < n; i += 2)
        chan.pb(a[i]);

    sort(all(le));
    sort(all(chan), greater<int>());

    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << le[p++] << " ";
        else
            cout << chan[q++] << " ";
    }
    cout << "\n";
}