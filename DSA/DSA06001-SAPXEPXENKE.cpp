
/*

	Cho mảng A[] gồm n số nguyên khác nhau. Hãy đưa ra các phần tử của 
	
	mảng theo khuôn dạng lớn nhất, nhỏ nhất, lớn thứ hai, nhỏ thứ 2, … 
	
	Ví dụ với A[] = {9, 7, 12, 8, 6, 5} ta đưa ra : 12, 5, 9, 6, 8, 7.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng đầu tiên là số 
	
	phần tử của mảng n; dòng tiếp theo là n số A [i] 
	
	của mảng A [];các số được viết cách nhau một vài khoảng trống
	
	T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
Input					Output

2
7
7 1 2 3 4 5 6			7 1 6 2 5 3 4
8	
1 6 9 4 3 7 8 2			9 1 8 2 7 3 6 4

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
		int n;
		cin >> n;
		int a[n];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		int l = 1, r = n;
		while (l < r)
		{
			cout << a[r--] << " " << a[l++] << " ";
		}
		if (l == r)
		{
			cout << a[l];
		}
		cout << "\n";
	}
}