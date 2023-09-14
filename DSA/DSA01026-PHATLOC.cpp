/*
    Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” 

    nếu thỏa mãn các điều kiện sau:

        + Độ dài xâu ít nhất là 6

        + Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6

        + Không có 2 chữ số 8 nào ở cạnh nhau

        + Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.

    Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

Input

    Chỉ có 1 dòng ghi số N (5 < N < 16).

Output

    Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.

Ví dụ

Input           Output

6               866686

                866866

                868666

                868686    


*/


#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];

void ktao()
{
    for (int i = 0; i <= 1; i++)
        a[i] = i;
}

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0)
        ok = false;
    else
        a[i] = 1;
}

bool check()
{
    if (a[1] == 0 || a[n] == 1)
        return false;
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == 1 && a[i + 1] == 1)
            return false;
    }
    for (int i = 1; i <= n - 3; i++)
    {
        if (a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0 && a[i + 3] == 0)
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    ok = true;
    ktao();
    while (ok)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 0)
                    cout << 6;
                else
                    cout << 8;
            }
            cout << endl;
        }
        sinh();
    }
    return 0;
}