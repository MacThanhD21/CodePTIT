/*
    Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông 
    
    hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] 
    
    ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.

    Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại 
    
    mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất 
    
    mà người đó phải bỏ ra.

    Dữ liệu vào: 
    
        Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); 
        
        n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

    Kết quả: 
    
        Chi phí mà người đó phải bỏ ra.

Ví dụ:

INPUT               OUTPUT

4                   117

0 20 35 10

20 0 90 50

35 90 0 12

10 50 12 0

*/


#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll c[1001][1001], MIN, n, res = (int)1e9, x[100001] = {0};
bool visited[1000001] = {0};

void back_track(ll i, ll sum)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            x[i] = j;
            visited[j] = true;
            sum += c[j][x[i - 1]];
            if (i == n)
            {
                sum += c[x[i]][1];
                res = min(res, sum);
            }
            if (sum + (n - i + 1) * MIN < res)
                back_track(i + 1, sum);
            visited[j] = false;
            sum -= c[j][x[i - 1]];
        }
    }
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            MIN = min(MIN, c[i][j]);
        }
    }
}

int main()
{
    init();
    visited[1] = true;
    x[1] = 1;
    back_track(2, 0);
    cout << res << endl;
}