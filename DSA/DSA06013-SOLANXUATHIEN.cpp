
/*

	Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy tìm số lần xuất hiện 
	
	số X trong mảng. Nếu số lần xuất hiện số x trong mảng là 0 hãy đưa ra -1.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test.
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N và X; 
	
	dòng tiếp theo đưa vào n số A[i]; các số được viết 
	
	cách nhau một vài khoảng trống.

	T, N, X, A[i] thỏa mãn ràng buộc: 
	
	1≤T≤100; 1≤ N ≤103, 1≤A[i], X ≤106.
Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input					Output

2
7 2

1 1 2 2 2 2 3			4

7 4

1 1 2 2 2 2 3			-1

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
		map<int, int> mp;
		for (int &x : u)
		{
			cin >> x;
			mp[x]++;
		}
		bool check = false;
		for (auto u : mp)
		{
			if (u.first == k)
			{
				cout << u.second << "\n";
				check = true;
			}
		}
		if (!check)
			cout << "-1\n";
	}
}