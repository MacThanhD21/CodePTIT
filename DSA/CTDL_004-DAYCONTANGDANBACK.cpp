
/*

    Cho ai, ci , W, N (i =1, 2,..,N; N£100) là những số nguyên dương  và tập hợp

    Hãy viết chương trình tìm phương án tối ưu XOPT =(x1,x2,..,xN) và giá trị tối 
    
    ưu FOPT=F(XOPT) của hàm mục tiêu

    Dữ liệu vào cho bởi file data.in theo khuôn dạng sau:

    Dòng đầu tiên ghi lại số tự nhiên N và W. Hai số được viết cách nhau một vài khoảng trống;

    Dòng kế tiếp ghi lại N số cj (j=1,2,..,N). Hai số được viết cách nhau một vài khoảng trống;

    Dòng kế tiếp ghi lại N số aj (j=1,2,..,N). Hai số được viết cách nhau một vài khoảng trống;

    Giá trị tối ưu FOPT và phương án XOPT tìm được sẽ liệt kê trên màn hình theo khuôn dạng:

    Dòng đầu tiên ghi lại giá trị tối ưu FOPT;

    Dòng kế tiếp ghi lại phương án tối ưu XOPT. Hai phần tử 
    
    khác nhau của phương án tối ưu được viết cách nhau bởi một khoảng trống.
    
    Ví dụ sau sẽ minh họa khuôn dạng cho file data.in  của bài toán.

data.in                                                                           

4                      10                               

6          5          3          7    

5          4          6          5

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;

#define pb push_back

vector<int> ans;
int n, k;
int a[105];
int cnt = 0, ans = 0;

void back(int i)
{
    for (int j = i + 1; j <= n; i++)
    {
        if (a[j] > a[i])
        {
            ++cnt;
            if (cnt == k)
                ++ans;
            back(j);
            --cnt;
        }
    }
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cnt = ans = 0;
    back(0);
    cout << ans << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}