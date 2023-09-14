
/*

    Cho hai số nguyên dương N và S. Hãy lựa chọn các chữ số phù hợp 
    
    để tạo ra số nhỏ nhất và số lớn nhất có N chữ số sao cho tổng chữ số đúng bằng S.

Input

    Chỉ có một dòng ghi hai số N và S. 
    
    (0 < N <= 100; 0 <= S <= 900)

Output

    Ghi ra hai số nhỏ nhất và lớn nhất tìm được, 
    
    cách nhau một khoảng trống.

    Nếu không thể tìm được thì ghi ra “-1 -1”

Ví dụ

Input           Output

3 20            299 992

2 900           -1 -1

3 0             -1 -1

*/

#include <bits/stdc++.h>

using namespace std;

void smallest(int s, int n)
{
    if (s == 0)
    {
        if (n == 1)
            cout << 0 << " ";
        else
            cout << -1 << " ";
        return;
    }
    if (s > 9 * n)
    {
        cout << -1 << " ";
        return;
    }
    int a[n];
    s -= 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (s > 9)
        {
            a[i] = 9;
            s -= 9;
        }
        else
        {
            a[i] = s;
            s = 0;
        }
    }
    a[0] = s + 1;
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << " ";
}

void biggest(int s, int n)
{
    if (s == 0)
    {
        if (n == 1)
            cout << 0 << " ";
        else
            cout << -1 << " ";
        return;
    }
    if (s > 9 * n)
    {
        cout << -1 << endl;
        return;
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        if (s > 9)
        {
            b[i] = 9;
            s -= 9;
        }
        else
        {
            b[i] = s;
            s = 0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << b[i];
}

int main()
{
    int n, s;
    cin >> n >> s;
    smallest(s, n);
    biggest(s, n);
    return 0;
}