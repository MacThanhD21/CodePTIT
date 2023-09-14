
/*

    Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

    Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các 
    
    chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không 
    
    tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

    Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input

    Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output

    Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.

Ví dụ

Input           Output

D 2             AA

                AB

                AC

                AD

                BB

                BC

                BD

                CC

                CD

                DD

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

char c;
int k, n, ok = 1;

int x[100];

void gernerate()
{
    int i = k;
    while (i >= 1 && x[i] == n)
        --i;
    if (i == 0)
    {
        ok = 0;
    }
    else
    {
        ++x[i];
        for (int j = i + 1; j <= k; j++)
            x[j] = x[i];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> c >> k;
    n = c - 'A' + 1;
    for (int i = 1; i <= k; i++)
    {
        x[i] = 1;
    }
    ok = 1;
    while (ok)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << char(x[i] + 64);
        }
        cout << "\n";
        gernerate();
    }
}