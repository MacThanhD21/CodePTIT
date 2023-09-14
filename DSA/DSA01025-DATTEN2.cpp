
/*
    Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa. 

    Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái (không trùng nhau) 

    và sắp xếp lại theo thứ tự từ điển.

    Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

Input

    Dòng đầu ghi số bộ test T (không quá 10)

    Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)

Output

    Với mỗi bộ test, ghi ra tất cả các cái tên 
    
    có thể được tạo ra, mỗi kết quả viết trên một dòng.


Ví dụ

Input           Output

1

4 2             AB

                AC

                AD

                BC

                BD

                CD
*/


#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100];

void Back(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << (char)('A' + a[i] - 1);
            }
            cout << "\n";
        }
        else
        {
            Back(i + 1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Back(1);
    }
}
