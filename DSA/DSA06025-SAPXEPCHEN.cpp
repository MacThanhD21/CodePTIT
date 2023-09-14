

/*

    Hãy thực hiện thuật toán sắp xếp chèn trên dãy N số nguyên. 
    
    Ghi ra các bước thực hiện thuật toán.

Dữ liệu vào: 

    Dòng 1 ghi số N (không quá 100). 

    Dòng 2 ghi N số nguyên dương (không quá 100).

Kết quả: 

    Ghi ra màn hình từng bước thực hiện thuật toán. 

    Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.

Ví dụ:

Input               Output

4

5 7 3 2             Buoc 0: 5
                    Buoc 1: 5 7
                    Buoc 2: 3 5 7
                    Buoc 3: 2 3 5 7


*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int i = 0;
    multiset<int> ms;
    vector<int> v[1005];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
        for (auto x : ms)
        {
            v[i].pb(x);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "Buoc " << i << ": ";
        for (auto x : v[i])
            cout << x << " ";
        cout << "\n";
    }
}