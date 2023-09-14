
/*
    Kỳ thi ICPC có K đội của PTIT tham gia và 
    
    đội tuyển đang rất đau đầu không biết chọn

    các cái tên như thế nào cho các đội. Yêu cầu 
    
    phải đảm bảo tên không có khoảng trống và

    không được trùng nhau. Sau khi thảo luận, có 
    
    N cái tên được đề xuất (có thể bị trùng nhau).

    Với K<15 và 4 < N < 30.

    Hãy liệt kê tất cả danh sách các tổ hợp K cái tên 
    
    khác nhau có thể được tạo ra theo thứ tự từ điển.

Input

    Dòng đầu ghi 2 số N và K.

    Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên 
    
    có độ dài không quá 15 và cách nhau một 
    
    khoảng trống. Tất cả đều là ký tự in hoa.

Output

    Ghi ra tất cả các tổ hợp tên có thể được 
    
    lựa chọn theo thứ tự từ điển.

    Tức là các tên trong mỗi tổ hợp liệt kê theo thứ 
    
    tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.

Ví dụ

Input                                   Output

6 2

DONG TAY NAM BAC TAY BAC                BAC DONG

                                        BAC NAM

                                        BAC TAY

                                        DONG NAM

                                        DONG TAY

                                        NAM TAY
*/

#include <bits/stdc++.h>

using namespace std;

string a[100];
set<string> s;
int x[100];
int n, k;

int idx = 1;

void Input()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        string res;
        cin >> res;
        s.insert(res);
    }

    for (string x : s)
    {
        a[idx++] = x;
    }
    --idx;
}

void Back(int i)
{
    for (int j = x[i - 1] + 1; j <= idx - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            for (int h = 1; h <= k; h++)
            {
                cout << a[x[h]] << " ";
            }
            cout << "\n";
        }
        else
            Back(i + 1);
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

    Input();
    Back(1);
}
