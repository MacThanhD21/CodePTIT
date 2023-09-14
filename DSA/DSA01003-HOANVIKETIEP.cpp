/*

	Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. 

	Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[].

	Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

Input:

	Dòng đầu tiên đưa vào số lượng test T.

	Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: 

	dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.

	T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.

Output:
	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

2

5 

1  2  3  4  5			1 2  3  5  4

5

5  4  3  2  1			1 2  3  4  5
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define faster()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

int main()
{
	faster();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int w[n];
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
		}
		bool ok = false;
		while (next_permutation(w + 1, w + n + 1))
		{
			for (int i = 1; i <= n; i++)
			{
				cout << w[i] << " ";
			}
			ok = true;
			break;
		}
		if (!ok)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
		}
		cout << "\n";
	}
}