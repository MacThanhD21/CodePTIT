

/*

	Cho mảng A[] gồm n số nguyên dương và số k. Nhiệm vụ của bạn 

	là đếm số các cặp phần tử có hiệu nhỏ hơn k. Ví dụ 
	
	A[] = {1, 10, 4, 2 }, k=3 ta nhận được kết quả là 2 
	
	tương ứng với hiệu các cặp (1, 2), (4, 2).

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, 
	
	tương ứng với số phần tử của mảng A[] và số k; 
	
	dòng tiếp theo là n số A[i] ; các số được viết 
	
	cách nhau một vài khoảng trống.

	T, n, k, A[i] thỏa mãn ràng buộc: 
	
	1 ≤ T ≤ 100; 1 ≤n≤ 104; 1 ≤k ≤ 103; 1 ≤ A[i] ≤ 105.
Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input				Output

2
4 3
1 10 4 2			2
3 5
2 3 4				3

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (auto &x : a)
			cin >> x;
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			auto pos = lower_bound(a + i + 1, a + n, a[i] + k) - a;
			--pos;
			cout << pos << " ";
			if (pos != -1)
			{
				ans += (pos - i);
			}
		}
		cout << ans << "\n";
	}
}
