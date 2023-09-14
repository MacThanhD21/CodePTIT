/*

	Hãy in ra tất cả các xâu nhị phân độ dài N, 
	
	có K bit 1 theo thứ tự từ điển tăng dần.

Input: 
	Dòng đầu tiên là số lượng bộ test T (T ≤ 20). 

	Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).

Output:  

	Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

Ví dụ:

Input			Output

2				0011

4 2				0101

3 2				0110

				1001

				1010

				1100

				011

				101

				110



*/

#include <bits/stdc++.h>
using namespace std;

int n, a[1010], k;
bool ok = false;

void ktao()
{
	for (int i = 1; i <= n; i++)
		a[i] = 0;
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i] == 1)
	{
		a[i] = 0;
		--i;
	}
	if (i == 0)
		ok = false;
	else
		a[i] = 1;
}

bool check()
{
	int sum1 = 0;
	for (int i = 1; i <= n; i++)
		sum1 += a[i];
	if (sum1 != k)
		return false;
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	ktao();
	while (t--)
	{
		cin >> n >> k;
		ok = true;
		int sum = 0;

		while (ok)
		{
			if (check())
			{
				for (int i = 1; i <= n; i++)
					cout << a[i];
				cout << "\n";
			}
			sinh();
		}
	}
}