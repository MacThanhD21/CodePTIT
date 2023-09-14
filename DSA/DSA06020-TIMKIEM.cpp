
/*

	Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy đưa ra 1 nếu X 
	
	có mặt trong mảng A[], ngược lại đưa ra -1.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào 
	
	n, X là số các phần tử của mảng A[] và số X cần tìm; 
	
	dòng tiếp theo đưa vào n số A[i] (1≤i≤n) các số được 
	
	viết cách nhau một vài khoảng trống.

	T, n, A, X thỏa mãn ràng buộc: 1≤T≤100; 1≤N, X, A[i] ≤106.
Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input						Output

2 
5 16
2 4 7 9 16					1
7 98
1 22 37 47 54 88 96			-1

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
		int n, k;
		cin >> n >> k;
		int a[n], b[1000005] = {0};
		for (int &x : a)
		{
			cin >> x;
			b[x] = 1;
		}
		if (b[k])
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}
}
