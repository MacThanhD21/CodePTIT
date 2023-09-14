
/*

	Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục của mảng 
	
	A[R], .., A[L] sao cho khi sắp xếp lại dãy con ta nhận được một mảng được sắp xếp. 
	
	Ví dụ với A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60} 
	
	ta chỉ cần sắp xếp lại dãy con từ A[4],.., A[9]: {30, 25, 40, 32, 31, 35} 
	
	để có mảng được sắp.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số 
	
	phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng
	
	A[]các số được viết cách nhau một vài khoảng trống.

	T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤106; 0≤ A[i] ≤107.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input									Output

2
11
10 12 20 30 25 40 32 31 35 50 60		4 9
9
0 1 15 25 6 7 30 40 50					3 6

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n);
		int idx1, idx2;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				idx1 = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] != b[i])
			{
				idx2 = i;
				break;
			}
		}
		cout << idx1 + 1 << " " << idx2 + 1 << "\n";
	}
}