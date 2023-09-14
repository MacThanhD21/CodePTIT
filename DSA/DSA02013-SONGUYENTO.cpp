/*

    Cho ba số N, P, S. Trong đó, P là một số nguyên tố. 

    Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố lớn hơn P có tổng bằng S. 

    Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. 

    Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 

    Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.

    S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.

Output:

    Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. 

    Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.


Input               Output

2
2  7  28            1
                    11 17

3  2  23            2
                    3 7 13
                    5 7 11  
                    
*/

#include <bits/stdc++.h>

using namespace std;

int N, P, S;
vector<vector<int>> v;
vector<int> SNT;

int n;
bool nt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void get()
{
    SNT.push_back(0);
    for (int i = P + 1; i <= S; i++)
    {
        if (nt(i))
        {
            SNT.push_back(i);
        }
    }
    n = SNT.size() - 1;
}

void back(int i, int pre, int sum, vector<int> Q, int k)
{
    for (int j = pre + 1; j <= n - k + i; j++)
    {
        Q.push_back(j);
        sum += SNT[j];
        if (i == k && sum == S)
            v.push_back(Q);
        else if (i < k)
        {
            back(i + 1, j, sum, Q, k);
        }
        sum -= SNT[j];
        Q.pop_back();
    }
}

void solve()
{
    cin >> N >> P >> S;
    get();

    vector<int> Q;
    back(1, 0, 0, Q, N);

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto x : v)
    {
        for (auto u : x)
        {
            cout << SNT[u] << " ";
        }
        cout << "\n";
    }
    SNT.clear();
    v.clear();
}
int main()
{

    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return (0 ^ 0);
}