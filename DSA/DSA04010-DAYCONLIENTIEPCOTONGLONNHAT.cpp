
/*

    Cho mảng A[] gồm N số có cả các số âm và số dương. 

    Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. 
    
    Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 
    
    tương ứng với dãy con {6, -2, -3, 1, 5}.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào 
    
    hai số N tương ứng với số phần tử của mảng; 
    
    dòng tiếp theo đưa vào N số A[i]; các số được 
    
    viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;1≤ N≤100; -100≤A[i] ≤100.

Output:

    Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.

Ví dụ:

Input                       Output

1
8
-2 -5 6 -2 -3 1 5 -6        7

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &X : a)
            cin >> X;
        ll sum1 = 0, ans = LLONG_MIN;
        for (int x : a)
        {
            sum1 += 1ll * x;
            if (sum1 < 0)
                sum1 = 0;
            ans = max(ans, sum1);
        }
        cout << ans << "\n";
    }
}