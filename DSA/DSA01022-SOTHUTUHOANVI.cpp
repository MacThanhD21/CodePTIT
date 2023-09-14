

/*
	Cho một hoán vị của N số nguyên dương đầu tiên.

	Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu 
	
	liệt kê theo thứ tự tăng dần (tính từ 1).

Input

	Dòng đầu ghi số T là số bộ test (T < 10)

	Mỗi bộ test gồm 2 dòng

	Dòng đầu ghi số nguyên dương N (3 < N < 10)

	Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.  
	
Output

	Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị

	(tính từ 1, theo thứ tự liệt kê tăng dần).

Ví Dụ:

Input 			Output

2

4

1 4 3 2			6

4

1 2 3 4			1

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
		int a[n], b[n];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			b[i] = i;
		}
		do
		{
			bool check = true;
			++ans;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] != b[i])
				{
					check = false;
				}
			}
			if (check)
				cout << ans << "\n";
		} while (next_permutation(b + 1, b + n + 1));
	}
}