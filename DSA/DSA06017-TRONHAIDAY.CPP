

/*

    Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. 
    
    Nhiệm vụ của bạn là hợp nhất hai mảng A[] và B[] để 
    
    được một mảng mới đã được sắp xếp. Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 }, 
    
    B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là C[] = {-1, 1, 0, 2, 3, 5, 6, 6, 7.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test. 
    
    Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào 
    
    n, m tương ứng với số phần tử của mảng A[] và B[]; 
    
    dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số 
    
    B[i]; các số được viết cách nhau một vài khoảng trống.

    T, n, m, A[i], B[i] thỏa mãn ràng buộc: 
    
    1≤ T ≤100; 1≤ n, m ≤106; -108≤ A[i] ≤108.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input               Output

1

3 3

10 5 15             2 3 5 10 15 20

20 3 2

*/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int F[n + m];
        for (int i = 0; i < n + m; i++)
        {
            cin >> F[i];
        }
        sort(F, F + (n + m));
        for (auto x : F)
            cout << x << " ";
        cout << "\n";
    }
}