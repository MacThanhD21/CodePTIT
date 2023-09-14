
/*

	Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. 
	
	Nhiệm vụ của bạn là tìm tích giữa phần tử lớn nhất của mảng 
	
	A[] và phần tử nhỏ nhất của mảng B[]. Ví dụ 
	
	A[] = {5, 7, 112, 9, 3, 6, 2 }, B[] = {1, 2, 6, -1, 0, 9} 
	
	ta có kết quả là -9 = 9*(-1).

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa 
	
	vào n, m tương ứng với số phần tử của mảng A[] và B[]; 
	
	dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số B[i]; 
	
	các số được viết cách nhau một vài khoảng trống.

	T, n, m, A[i], B[i] thỏa mãn ràng buộc: 
	
	1≤ T ≤100; 1≤ n, m ≤106; -108≤ A[i] ≤108.
Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input					Output

2
6 6
5 7 9 3 6 2
1 2 6 -1 0 9			-9
6 6

1 4 2 3 10 2
4 2 6 5 2 9				20

*/



#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

const int N = 2e7 + 5;
const int mod = 1e9 + 7;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int c[n + m];
		for (auto &x : c)
			cin >> x;
		sort(c, c + n + m);
		for (auto x : c)
			cout << x << " ";
		cout << "\n";
	}
}
