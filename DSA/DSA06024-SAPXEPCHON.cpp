
/*

	Hãy thực hiện thuật toán sắp xếp chọn trên dãy N số nguyên. 
	
	Ghi ra các bước thực hiện thuật toán.

Dữ liệu vào: 

	Dòng 1 ghi số N (không quá 100). 

	Dòng 2 ghi N số nguyên dương (không quá 100).

Kết quả: 

	Ghi ra màn hình từng bước thực hiện thuật toán. 

	Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.

Ví dụ:

Input			Output

4

5 7 3 2			Buoc 1: 2 7 3 5
				Buoc 2: 2 3 7 5
				Buoc 3: 2 3 5 7

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (auto &x : a)
		cin >> x;
	int cnt = 0;
	vector<int> v[1005];
	for (int i = 0; i < n - 1; i++)
	{
		int min = a[i], idex = i;
		for (ll j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				idex = j;
			}
		}
		swap(a[i], a[idex]);
		for (int k = 0; k < n; k++)
		{
			v[i].pb(a[k]);
		}
	}
	for (int i = n - 1; i >= 1; i--)
	{
		cout << "Buoc " << i << ": ";
		for (auto x : v[i - 1])
			cout << x << " ";
		cout << "\n";
	}
}