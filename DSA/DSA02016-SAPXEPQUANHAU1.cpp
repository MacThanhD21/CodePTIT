/*
    Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể 

    di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n quân hậu, 

    bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, 

    chúng không “ăn” nhau.

Input: 

    Dòng đầu ghi số bộ test T (T<5). 

    Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)

Output:  

    Ghi kết quả mỗi bộ test trên một dòng. 

    Số cách đặt quân hậu.

Ví dụ:

Input           Output

1

4               2
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;

#define ms(a) memset(a, 0, sizeof(a))

int n;
int b[100]; // cot
int c[100]; // duong cheo chinh
int d[100]; // duong cheo phu
int cnt;

void back(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!b[j] && !c[i + j - 1] && !d[i - j + n])
        {
            b[j] = c[i + j - 1] = d[i - j + n] = 1;
            if (i == n)
                ++cnt;
            else
                back(i + 1);
            b[j] = c[i + j - 1] = d[i - j + n] = 0;
        }
    }
}

void solve()
{
    cin >> n;
    ms(b); ms(c); ms(d);
    cnt = 0;
    back(1);
    cout << cnt << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}