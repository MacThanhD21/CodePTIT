/*

	Cho mảng A[] gồm các số từ 0 đến 9. Nhiệm vụ của bạn là tìm tổng nhỏ nhất 
	
	của hai số được tạo bởi các số trong mảng A[]. Chú ý, tất cả các số trong 
	
	mảng A[] đều được sử dụng để tạo nên hai số.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào 
	
	số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] 
	
	tương ứng với các phần tử của mảng A[]; các số được viết cách 
	
	nhau một vài khoảng trống.

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤20; 0≤A[i]≤9.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
	
Ví  dụ:

Input				Output

2
6					604 	
6 8 4 5 2 3
5					82
5 3 0 7 4

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
		int n;
		cin >> n;
		int a[n];
		for (int &x : a)
			cin >> x;
		ll sum1 = 0, sum2 = 0;
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				sum1 = sum1 * 10 + a[i];
			}
			else
			{
				sum2 = sum2 * 10 + a[i];
			}
		}
		//		cout << sum1 << " " << sum2 << "\n";
		cout << sum1 + sum2 << "\n";
	}
}
