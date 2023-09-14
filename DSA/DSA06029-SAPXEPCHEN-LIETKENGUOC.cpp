
/*

    Cho dãy số A[] có n phần tử là các số nguyên dương. 
    
    Hãy sắp xếp dãy số theo thuật toán sắp xếp chèn. 
    
    Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán 
    
    theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

Input

    Dòng đầu ghi số n (1 < n < 100)

    Dòng thứ 2 ghi n số của dãy A 
    
    (các số đều nguyên dương và nhỏ hơn 100000)

Output

    Ghi ra lần lượt các bước thuật toán theo 
    
    thứ tự ngược (xem ví dụ mẫu để hiểu rõ hơn).

Ví dụ

Input                   Output

6

5 8 3 9 1 4             Buoc 5: 1 3 4 5 8 9
                        Buoc 4: 1 3 5 8 9
                        Buoc 3: 3 5 8 9
                        Buoc 2: 3 5 8
                        Buoc 1: 5 8
                        Buoc 0: 5

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    multiset<int> ms;
    vector<int> v[10005];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
        for (auto x : ms)
        {
            v[i].push_back(x);
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