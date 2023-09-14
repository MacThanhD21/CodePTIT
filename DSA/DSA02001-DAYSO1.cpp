

/*
	Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác

	được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử

	liên tiếp của hàng i-1 (2≤i≤n). Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo

	nên như dưới đây:

	[1, 2, 3, 4, 5 ]

	[3, 5, 7, 9 ]

	[8, 12, 16]

	[20, 28]

	[48]

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng tiếp theo đưa vào các bộ test.

	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa

	vào N là số lượng phần tử của dãy số A[]; dòng tiếp

	theo đưa vào N số của mảng A[].

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;

Output:

	Đưa ra tam giác tổng của mỗi test theo từng dòng.

	Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].

Input				Output

1

5

1 2 3 4 5			[1 2 3 4 5]

					[3 5 7 9]

					[8 12 16]

					[20 28]

					[48]
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

const int N = 2e7 + 5;

void Back(int n, int a[])
{
	if (n > 0)
	{
		cout << "[";
		for (int i = 1; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << a[n] << "]";
		cout << "\n";
		for (int i = 1; i < n; i++)
		{
			a[i] += a[i + 1];
		}
		Back(n - 1, a);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		Back(n, a);
	}
}
