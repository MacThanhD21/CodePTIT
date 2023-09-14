/*
    Cho mảng A[] gồm N số nguyên dương phân biệt và số X. 

    Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. 

    Các số trong mảng A[] có thể được sử dụng nhiều lần. 

    Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. 

    Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

    [2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; 
    
    dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.

    T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.

Output:

    Đưa ra kết quả mỗi test theo từng dòng. 
    
    Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. 
    
    Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.



Input               Output

1

4  8
2  4  6             [2 2 2 2] [2 2 4] [2 6] [4 4] [8]

*/


#include <bits/stdc++.h>

using namespace std;

int n, X;
int a[100];
vector<vector<int>> v;

void back(int pre, int sum, vector<int> res)
{
    for (int j = pre; j <= n; j++)
    {
        res.push_back(j);
        sum += a[j];
        if (sum == X)
        {
            v.push_back(res);
        }
        else if (sum < X)
        {
            back(j, sum, res);
        }
        sum -= a[j];
        res.pop_back();
    }
}
void solve()
{
    cin >> n >> X;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> res;
    back(1, 0, res);
    if (v.size() == 0)
    {
        cout << "-1\n";
    }
    else
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << "[";
            for (int i = 0; i < v[j].size() - 1; i++)
            {
                cout << a[v[j][i]] << " ";
            }
            cout << a[v[j][v[j].size() - 1]] << "]";
        }
    }
    cout << "\n";
    v.clear();
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}