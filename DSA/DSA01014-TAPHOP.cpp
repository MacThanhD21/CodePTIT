
/*

    Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau 
    
    và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có 
    
    tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả 
    
    các phần tử trong tập hợp bằng s?

    Các tập hợp là hoán vị của nhau chỉ được tính là một.

    Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

Input:  

    Gồm nhiều bộ test (không quá 100 test).

    Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. 
    
    Input kết thúc bởi 3 số 0.

Output:  
    Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

Ví dụ:

Input               Output

9 3 23              1

9 3 22              2

10 3 28             0

16 10 107           20

20 8 102            1542

20 10 105           5448

20 10 155           1

3 4 3               0

4 2 11              0

0 0 0

*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define is insert
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxx = 1e7 + 5;

int n, k, s;
vector<vector<int>> v;

int ans = 0;
void back(int i, int pre, int sum, vector<int> res)
{
    for (int j = pre + 1; j <= n - k + i; j++)
    {
        res.push_back(j);
        if (sum + j == s && i == k)
            v.push_back(res);
        else if (i < k)
            back(i + 1, j, sum + j, res);
        res.pop_back();
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (1)
    {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0)
        {
            break;
        }
        else
        {
            // ans = 0;
            v.clear();
            vector<int> res;
            back(1, 0, 0, res);
            cout << v.size() << "\n";
        }
    }
}