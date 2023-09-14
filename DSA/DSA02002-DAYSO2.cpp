
/*
	Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được

	tạo ra bởi n hàng, trong đó hàng thứ n là dãy số A[], hàng i là tổng hai phần tử liên tiếp 

	của hàng i+1 (1≤i≤n-1). Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:

	[48]

	[20, 28]

	[8, 12, 16]     

	[3, 5, 7, 9 ]

	[1, 2, 3, 4, 5 ]

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng tiếp theo đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất 
	
	đưa vào N là số lượng phần tử của dãy số A[]; 
	
	dòng tiếp theo đưa vào N số của mảng A[].

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;

Output:

Đưa ra kết quả mỗi test theo từng dòng. 

Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].

Input				Output

1

5

1 2 3 4 5			[48] [20 28] [8 12 16] [3 5 7 9 ] [1 2 3 4 5 ]

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

const int N = 2e7 + 5;

vector<vector<int>> v;

void solve(int a[], int n)
{
	while (n > 0)
	{
		vector<int> v1;
		for (int i = 0; i < n; i++)
		{
			v1.pb(a[i]);
		}
		v.pb(v1);
		for (int i = 0; i < n - 1; i++)
		{
			a[i] += a[i + 1];
		}
		n--;
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << "[";
		for (int j = 0; j < v[i].size() - 1; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << v[i][v[i].size() - 1] << "] ";
	}
	v.clear();
	cout << "\n";
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
		for (int &x : a)
			cin >> x;
		solve(a, n);
	}
}
