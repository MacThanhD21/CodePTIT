
/*

	Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. 
	
	Các phần tử của mảng A[] và B[] chưa được sắp xếp. 
	
	Hãy tìm mảng hợp và giao được sắp giữa A[] và B[]. 
	
	Ví dụ với A[] = {7, 1, 5, 2, 3, 6}, B[]={3, 8, 6, 20, 7} 
	
	ta có mảng hợp Union = {1, 2, 3, 5, 6, 7, 8, 20}, 
	
	mảng giao Intersection = {3, 6}.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m 
	
	là số phần tử của mảng A[] và B[]; dòng tiếp theo là 
	
	n số A [i] của mảng A [];dòng tiếp theo là m số B[i] 
	
	của mảng B[]; các số được viết cách nhau một vài khoảng trống.

	T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m, A[i], B[i] ≤105.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
Input			Output

1
6 5				1 2 3 5 6 7 8 20
7 1 5 2 3 6		2 6
3 8 6 20 7

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;
		sort(a, a + n);
		sort(b, b + m);
		vector<int> hop;
		vector<int> giao;
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			if (a[i] < b[j])
			{
				hop.pb(a[i]);
				++i;
			}
			else if (a[i] > b[j])
			{
				hop.pb(b[j]);
				++j;
			}
			else
			{
				hop.pb(a[i]);
				giao.pb(a[i]);
				++i;
				++j;
			}
		}
		while (i < n)
		{
			hop.pb(a[i++]);
		}
		while (j < m)
		{
			hop.pb(b[j++]);
		}
		for (int x : hop)
			cout << x << " ";
		cout << endl;
		for (int x : giao)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}