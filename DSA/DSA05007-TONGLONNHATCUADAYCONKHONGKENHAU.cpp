
/*

    Cho dãy số A[] gồm N phần tử. Hãy tìm tổng lớn nhất 
    
    của dãy con của dãy số A[] sao cho dãy con không có 
    
    hai số cạnh nhau trong A[]. Ví dụ với A[] = {6, 7, 1, 3, 8, 2, 4} 
    
    ta có kết quả là 19 tương ứng với tổng của dãy con {6, 1, 6, 4} 
    
    không có haI phần tử nào kề nhau trong A[].

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; 
    
    dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
    
Ví dụ:

Input               Output

2
6
5 5 10 100 10 5     110
4
3 2 7 10            13

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 5;

int dp[N], a[N];
int n;

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dp[0] = 0;
        dp[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        cout << dp[n] << "\n";
    }
}