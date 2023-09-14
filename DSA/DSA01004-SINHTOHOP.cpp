/*

	Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con 

	K phần tử của 1, 2, .., N. Ví dụ với N=5, K=3 ta có 10 tập con của 1, 2, 3, 4, 5 

	như sau: 
	
	{1, 2, 3}, {1, 2, 4},{1, 2, 5},{1, 3, 4},{1, 3, 5},
	
	{1, 4, 5},{2, 3, 4},{2, 3, 5},{2, 4, 5},{3, 4, 5}.

Input:

	Dòng đầu tiên đưa vào số lượng test T.

	Những dòng kế tiếp đưa vào các bộ test. 

	Mỗi bộ test là một cặp số tự nhiên N, K được viết trên một dòng.

	T, n thỏa mãn ràng buộc: 1≤T≤100; 1≤k ≤ n≤15.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input			Output

2

4  3			123 124 134 234

5  3			123 124 125 134 135 145 234 235 245 345
*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = (int)1e9 + 7;

#define faster()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

int n, k, a[100];
void out()
{
	for (int i = 1; i <= k; i++)
	{
		cout << a[i];
	}
	cout << " ";
}
void Try(int i)
{
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{
		a[i] = j;
		if (i == k)
		{
			out();
		}
		else
		{
			Try(i + 1);
		}
	}
}

void solve()
{
	cin >> n >> k;
	Try(1);
}

int main()
{

	faster();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
}