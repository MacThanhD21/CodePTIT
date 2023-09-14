
/*

    Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. 
    
    Không có 2 thẻ nào ghi hai số trùng nhau. Nam muốn xếp 
    
    thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

    Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.

    Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.  

Input

    Dòng đầu ghi số bộ test T (không quá 10)

    Mỗi bộ test ghi số N (3 < N < 10)

Output

    Với mỗi bộ test, ghi ra tất cả các cách xếp thứ tự thỏa mãn, 
    
    mỗi cách trên một dòng.
    
Ví dụ

Input           Output

1               2413

4               3142

*/

#include <bits/stdc++.h>

using namespace std;

bool check(int a[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        if (abs(a[i + 1] - a[i]) == 1)
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        do
        {
            if (check(a, n))
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << a[i];
                }
                cout << "\n";
            }
        } while (next_permutation(a + 1, a + n + 1));
    }
}
