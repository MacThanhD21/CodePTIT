
/*

	Cho mảng A[] gồm N phần tử chưa được sắp xếp. Nhiệm vụ của bạn 
	
	là sắp xếp các phần tử của mảng A[] theo thứ tự tăng dần bằng 
	
	thuật toán Merge Sort.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 

	Mỗi bộ test gồm hai phần: phần thứ nhất 
	
	đưa vào số N tương ứng với số phần tử của mảng A[]; 
	
	phần thứ 2 là N số của mảng A[]; các số được viết
	 
	cách nhau một vài khoảng trống.

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i]≤106.
Output:

	Đưa ra kết quả các test theo từng dòng.

Input						Output

2
5
4 1 3 9 7					1 3 4 7 9
10
10 9 8 7 6 5 4 3 2 1		1 2 3 4 5 6 7 8 9 10

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()

// MergeSort

void merge(int a[], int l, int m, int r)
{
	vector<int> a1(a + l, a + m + 1);	  // (l -> m)
	vector<int> a2(a + m + 1, a + r + 1); //(m + 1 -> r)

	int i = 0, j = 0;
	while (i < a1.size() && j < a2.size())
	{
		if (a1[i] < a2[j])
		{
			a[l++] = a1[i++];
		}
		else
		{
			a[l++] = a2[j++];
		}
	}
	while (i < a1.size())
	{
		a[l++] = a1[i++];
	}
	while (j < a2.size())
	{
		a[l++] = a2[j++];
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int &x : a)
		cin >> x;
	mergeSort(a, 0, n - 1);
	for (int x : a)
		cout << x << " ";
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
