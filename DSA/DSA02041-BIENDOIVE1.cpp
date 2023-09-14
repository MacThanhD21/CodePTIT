
/*

    Cho số nguyên dương N. Hãy đếm số bước ít nhất để đưa N về 1 
    
    bằng cách thực hiện ba thao tác dưới đây:

    + Nếu N chia hết cho 2 bạn có thể giảm N = N/2.

    + Nếu N chia hết cho 3 bạn có thể giảm N = N/3.

    + Giảm N đi 1.

    Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một số N được viết trên một dòng.

    T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.
    
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input           Output

2
10              3
6               2

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int ans;

void recursion(int n, int step)
{
    if (step > ans)
        return;
    if (n == 1)
    {
        ans = min(ans, step);
        return;
    }
    if (n % 2 == 0)
    {
        recursion(n / 2, step + 1);
    }
    if (n % 3 == 0)
    {
        recursion(n / 3, step + 1);
    }
    if (n >= 1)
    {
        recursion(n - 1, step + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = INT_MAX;
        recursion(n, 0);
        cout << ans << endl;
    }
}