
/*
    Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. 
    
    Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N; 
    
    dòng tiếp theo đưa vào N số của mảng A[]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤1000; 0≤ A[i]≤1.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
    
Ví dụ:

Input                           Output

3
12                              9
0 0 0 0 0 0 0 0 0 1 1 1         
5                               5
0 0 0 0 0
6                               0
1 1 1 1 1 1

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        auto it1 = lower_bound(a.begin(), a.end(), 0);
        auto it2 = upper_bound(a.begin(), a.end(), 0);
        if (it2 == a.end())
            ++it2;
        cout << (it2 - it1) - 1 << "\n";
    }
}