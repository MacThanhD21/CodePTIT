

/*

	Cho mảng A[] gồm n phần tử, hãy tìm cặp phần tử 
	
	có tổng gần nhất so với 0.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào 
	
	n là số phần tử của mảng A[]; dòng tiếp theo đưa vào 
	
	n số A[i]; các số được viết cách nhau một vài khoảng trống.

	T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 2≤N ≤103, -106≤A[i] ≤106.

Output:

	Đưa ra tổng gần nhất với 0 của cặp phần tử.

Input						Output

2
3
-8 -66 -60					-68

6
-21 -67 -37 -18 4 -65  		-14

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int &x : a)
			cin >> x;
		int e1 = -1, e2 = -1, min = INT_MAX;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (abs(a[i] + a[j]) < min)
				{
					min = abs(a[i] + a[j]);
					e1 = a[i];
					e2 = a[j];
				}
			}
		}
		cout << e1 + e2 << "\n";
	}
}