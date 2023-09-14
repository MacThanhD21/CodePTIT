
/*

    Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là đưa ra mảng 
    
    đã được sắp xếp bao gồm các chữ số của mỗi phần tử trong A[]. 
    
    Ví dụ A[] = {110, 111, 112, 113, 114 }ta có kết quả là {0, 1, 2, 3, 4}.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa 
    
    vào n là số phần tử của mảng A[]; dòng tiếp theo là 
    
    n số A[i] ; các số được viết cách nhau một vài khoảng trống.

    T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤107; 0≤ A[i] ≤1016.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Input               Output

2
3
131 11 48           1 3 4 8
4
111 222 333 446     1 2 3 4 6

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int M[N];
        set<int> se;
        for (int &x : M)
        {
            cin >> x;
            while (x != 0)
            {
                int u = x % 10;
                x /= 10;
                se.insert(u);
            }
        }
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}