
/*

	Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng. 
	
	Các phần tử được đưa ra theo thứ tự giảm dần.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N và K; 
	
	dòng tiếp theo đưa vào n số A[i]; các số được viết 
	
	cách nhau một vài khoảng trống.

	T, N, K, A[i] thỏa mãn ràng buộc: 
	
	1≤T≤100; 1≤K < N ≤103, 1≤A[i] ≤106.

Output:

	Đưa ra k phần tử lớn nhất trên một dòng.

Input				Output

2
5 3

10 7 9 12 6			12 10 9

6 2

9 7 12 8 6 5		12 9

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int u[n];
		for (int &x : u)
		{
			cin >> x;
		}
		sort(u, u + n, greater<int>());
		for (int i = 0; i < k; i++)
		{
			cout << u[i] << " ";
		}
		cout << "\n";
	}
}