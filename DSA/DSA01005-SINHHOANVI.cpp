/*
	Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị 

	của 1, 2, .., N. Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.

Input:

	Dòng đầu tiên đưa vào số lượng test T.
	
	Những dòng kế tiếp đưa vào các bộ test. 

	Mỗi bộ test là một số tự nhiên N được viết trên một dòng.

	T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = (int)1e9 + 7;

#define faster()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

int n, a[100];
bool f[100];
void out()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << " ";
}
void Try(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (f[j] == false)
		{
			a[i] = j;
			f[j] = true;
			if (i == n)
				out();
			else
				Try(i + 1);
			f[j] = false;
		}
	}
}

void solve()
{
	cin >> n;
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