
/*

	Cho mảng A[] gồm n số nguyên. Nhiệm vụ của bạn là sắp xếp mảng 
	
	theo số lần xuất hiện các phần tử của mảng. Số xuất hiện nhiều 
	
	lần nhất đứng trước. Nếu hai phần tử có số lần xuất hiện như nhau, 
	
	số nhỏ hơn đứng trước. Ví dụ A[] = {5, 5, 4, 6, 4 }, ta nhận được 
	
	kết quả là A[] = {4, 4, 5, 5, 6}.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào T bộ test. 
	
	Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, 
	
	tương ứng với số phần tử của mảng A[] và số k; dòng 
	
	tiếp theo là n số A[i] ; các số được viết cách nhau 
	
	một vài khoảng trống.

	T, n, A[i] thỏa mãn ràng buộc: 
	
	1≤ T ≤100; 1≤ n ≤104; 1≤ k ≤103; 1≤ A[i] ≤105.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input				Output

2
5
5 5 4 6 4			4 4 5 5 6
5
9 9 9 2 5			9 9 9 2 5

*/

#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

bool cmp(int a, int b)
{
	if (mp[a] != mp[b])
		return mp[a] > mp[b];
	return a < b;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int &x : a)
		{
			cin >> x;
			mp[x]++;
		}
		sort(a, a + n, cmp);
		for (int x : a)
			cout << x << " ";
		cout << "\n";
		mp.clear();
	}
}