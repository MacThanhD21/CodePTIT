
/*

    Ban đầu dãy số A[] gồm N phần tử đã được sắp xếp tăng dần. 
    
    Các phần tử của dãy A[] có thể giống nhau. Sau đó ta thực hiện 
    
    quay vòng phải, mỗi lần lấy một ký tự ở cuối dãy đưa lên đầu dãy.

    Cho trạng thái dãy số của A[] sau khi đã thực hiện quay vòng K lần. Hãy tìm K.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số M, N, K; 
    
    dòng tiếp theo đưa vào N số của mảng A[]các số được viết 
    
    cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤1018.

Output:

    Đưa ra số lần quay vòng K của mỗi test theo từng dòng.

Ví dụ:

Input               Output

2
5
5 1 2 3 4           1
5
1 2 3 4 5           0

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool ok = false;
        int pos = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                ok = true;
                pos = i;
                break;
            }
        }
        if (ok)
            cout << pos << "\n";
        else
            cout << "0\n";
    }
}
