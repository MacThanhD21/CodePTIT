
/*

	Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. 
	
	Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để 
	
	nhận được một mảng được sắp xếp.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số M, N, K; 
	
	dòng tiếp theo đưa vào M số của mảng A[];
	
	dòng tiếp theo đưa vào N số của mảng B[];
	
	các số được viết cách nhau một vài khoảng trống.

	T, M,N, A[i], B[i] thỏa mãn ràng buộc: 
	
	1≤T≤100;  1≤ N, A[i], B[i]≤106; 1≤ K≤N+M.

Output:

Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.

Ví dụ:

Input			Output

1
5 4 5			6
2 3 6 7 9
1 4 8 10


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
		int n, m, k;
		cin >> n >> m >> k;
		int A[n + m];
		for (int i = 1; i <= n + m; i++)
		{
			cin >> A[i];
		}
		sort(A + 1, A + (m + n));
		cout << A[k] << "\n";
	}
}
