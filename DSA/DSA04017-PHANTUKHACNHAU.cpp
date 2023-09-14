
/*

	Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. 
	
	Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. 
	
	Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N; 
	
	dòng tiếp theo đưa vào N số của mảng A[];
	
	dòng tiếp theo đưa vào N-1 số của mảng B[]; 
	
	các số được viết cách nhau một vài khoảng trống.

	T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤1018.
Output:

	Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input					Output

2
7
2 4 6 8 9 10 12			5
2 4 6 8 10 12
6
3 5 7 9 11 13			4
3 5 7 11 13

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
		int m = n - 1;
		int a[n], b[m];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= m; i++)
			cin >> b[i];
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != b[i])
			{
				cout << i << "\n";
				break;
			}
		}
	}
}
