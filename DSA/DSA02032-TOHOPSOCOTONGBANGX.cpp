
/*

    Cho mảng A[] gồm N số nguyên dương phân biệt và số X.

    Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. 

    Các số trong mảng A[] có thể được sử dụng nhiều lần. 

    Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. 

    Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

    {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

Input: 

    Dòng đầu tiên đưa vào số lượng bộ test T. 
    
    Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: 
    
    phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mảng A[]; 
    
    các số được viết cách nhau một vài khoảng trống. T, N, X, A[i] 
    
    thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.

Output:

    Đưa ra kết quả mỗi test theo từng dòng. 
    
    Đầu tiên là số lượng  tổ hợp thỏa mãn. 
    
    Mỗi tổ hợp được bao bởi cặp ký tự { } và 
    
    cách nhau một dấu cách. Đưa ra -1 nếu không 
    
    có tổ hợp nào thỏa mãn yêu cầu bài toán.

Ví dụ:

Input               Output

2
4  8

2  4  6  8          5 {2 2 2 2} {2 2 4} {2 6} {4 4} {8}

2 9

10 11               -1

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, a[105];
vector<vector<int>> v;

void back(int i, int sum, vector<int> b)
{
    for (int j = i; j <= n; j++)
    {
        b.push_back(a[j]);
        sum += a[j];
        if (sum == k)
        {
            v.push_back(b);
        }
        else if (sum < k)
        {
            back(j, sum, b);
        }
        sum -= a[j];
        b.pop_back();
    }
}

void solve()
{
    v.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> k;
    back(1, 0, k);

    if (!v.size())
    {
        cout << "-1\n";
        return;
    }
    else
    {

        cout << v.size() << " ";
        for (auto x : v)
        {
            cout << "{";
            for (int i = 0; i < x.size() - 1; i++)
            {
                cout << x[i] << " ";
            }
            cout << x[x.size() - 1] << "} ";
        }
    }
    cout << "\n";
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