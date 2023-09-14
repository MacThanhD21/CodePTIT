

/*

    Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau 
    
    từng đôi một và một số K < N.

    Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], 
    
    mỗi dãy đều được sắp xếp theo thứ tự tăng dần.

    Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

Input

    Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

    Dòng đầu ghi hai số N và K (2 < K < N <15)

    Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, 
    
    nhỏ hơn 100 và khác nhau từng đôi một.
    
Output

    Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, 
    
    mỗi dãy con trên một dòng. 

Ví dụ

Input               Output

1

4 3

3 2 5 4             2 3 4

                    2 3 5

                    2 4 5

                    3 4 5

*/


#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, k, a[N];

void init()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void ou(vector<int> q)
{
    for (auto i : q)
        cout << a[i] << " ";
    cout << "\n";
}

void back(int i, int pre, vector<int> q)
{
    for (int j = pre + 1; j <= n - k + i; j++)
    {
        q.push_back(j);
        if (i == k)
        {
            ou(q);
        }
        else
        {
            back(i + 1, j, q);
        }
        q.pop_back();
    }
}

void solve()
{
    init();
    vector<int> q;
    back(1, 0, q);
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}