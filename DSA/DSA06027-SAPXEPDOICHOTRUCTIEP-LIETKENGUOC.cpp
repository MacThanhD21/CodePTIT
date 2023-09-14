

/*

    Cho dãy số A[] có n phần tử là các số nguyên dương. 
    
    Hãy sắp xếp dãy số theo thuật toán sắp xếp đổi chỗ trực tiếp. 
    
    Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán 
    
    theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

Input

    Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm 2 dòng:

    Dòng đầu ghi số n (1 < n < 100)

    Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 1000)

Output

    Ghi ra lần lượt các bước thuật toán theo thứ tự ngược 
    
    (xem ví dụ mẫu để hiểu rõ hơn).

Ví dụ

Input               Output

1

6

5 8 3 9 1 4         Buoc 5: 1 3 4 5 8 9
                    Buoc 4: 1 3 4 5 9 8
                    Buoc 3: 1 3 4 9 8 5
                    Buoc 2: 1 3 8 9 5 4
                    Buoc 1: 1 8 5 9 3 4


*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (auto &x : a)
            cin >> x;
        vector<ll> v[1005];
        for (ll i = 0; i < n - 1; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                if (a[j] < a[i])
                {
                    swap(a[j], a[i]);
                }
            }
            for (int k = 0; k < n; k++)
            {
                v[i].pb(a[k]);
            }
        }
        for (int i = n - 1; i >= 1; i--)
        {
            cout << "Buoc " << i << ": ";
            for (auto x : v[i - 1])
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}