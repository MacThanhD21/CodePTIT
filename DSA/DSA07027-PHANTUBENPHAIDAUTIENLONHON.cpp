
/*

    Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử 
    
    bên phải đầu tiên lớn hơn nó. Nếu không tồn tại, in ra -1.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100000).

    Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).

Output: 

    Với mỗi test, in ra trên một dòng N số R[i], 
    
    với R[i] là giá trị phần tử đầu tiên lớn hơn A[i].

Ví dụ

Input               Output

3

4

4 5 2 25            5 25 25 -1

3

2 2 2               -1 -1 -1

4

4 4 5 5             5 5 -1 -1

*/

#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int &x : a)
        cin >> x;
    stack<int> st; // lưu chỉ số
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            a[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        a[st.top()] = -1;
        st.pop();
    }
    for (auto u : a)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}