
/*
	Cho số nguyên dương (1<N<40) và số nguyên dương K<N. 

	Với 1 tổ hợp chập K phần tử của N, hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu phần tử mới. 

	Nếu tổ hợp đã cho là cuối cùng thì kết quả là K.  

INPUT:
	Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng

	Dòng 1: hai số nguyên dương N và K (K<N)

	Dòng 2 ghi K số của tổ hợp ban đầu. Theo đúng thứ tự tăng dần, không có số nào trùng nhau.

OUTPUT: 
	Với mỗi bộ dữ liệu in ra số lượng phần tử mới.

Ví dụ:

INPUT				OUTPUT
3

5 3					1

1 3 5				2

5 3					4

1 4 5

6 4

3 4 5 6

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastIO()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

void solve()
{
	int n, k;
	cin >> n >> k;
	int a[k];
	set<int> se;
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
		se.insert(a[i]);
	}

	int j = k;
	while (j >= 1 && a[j] == n - k + j)
	{
		--j;
	}
	int ans = 0;
	a[j]++;
	for (int u = j + 1; u <= k; u++)
	{
		a[u] = a[u - 1] + 1;
	}
	for (int i = 1; i <= k; i++)
	{
		if (se.find(a[i]) == se.end())
			++ans;
	}
	cout << ans << "\n";
}

int main()
{

	fastIO();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}