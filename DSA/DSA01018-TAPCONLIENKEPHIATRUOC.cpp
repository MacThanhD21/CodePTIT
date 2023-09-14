/*

    Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. 

    Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử trước đó của X[]. Ví dụ N=5, K=3, 

    X[] ={2, 3, 5} thì tập con trước đó của X[] là {2, 3, 4}. Chú ý nếu tập con trong 

    input là đầu tiên thì trước đó là tập con cuối cùng.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; 
    
    dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.

    T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

2

5  3

2  3  5             2 3 4

5  3

1  2  3             3 4 5


*/

#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1, 0);
    for (int i = 1; i <= k; ++i)
        cin >> a[i];

    int i = k;
    while (i >= 1 && a[i] == a[i - 1] + 1)
        i--;
    if (i != 0)
        a[i]--;
    for (int j = i + 1; j <= k; ++j)
    {
        a[j] = n - k + j;
    }
    for (int j = 1; j <= k; ++j)
    {
        cout << a[j] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}