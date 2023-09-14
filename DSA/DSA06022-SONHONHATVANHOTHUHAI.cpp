
/*

	Cho mảng A[] gồm n phần tử, hãy đưa ra số nhỏ nhất và số nhỏ thứ hai của mảng. 
	
	Nếu không có số nhỏ thứ hai, hãy đưa ra -1.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n 
	
	là số phần tử của mảng A[]; dòng tiếp theo đưa vào 
	
	n số A[i]; các số được viết cách nhau một vài khoảng trống.

	T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤107.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input							Output

2
10
5 6 7 8 9 10 1 2 3 4			1 2
5
1 1 1 1 1						-1

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

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
		set<int> se;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			se.insert(a[i]);
		}
		if (se.size() == 1)
		{
			cout << -1 << "\n";
		}
		else
		{
			sort(a + 1, a + n + 1);
			cout << a[1] << " " << a[2] << "\n";
		}
	}
}
