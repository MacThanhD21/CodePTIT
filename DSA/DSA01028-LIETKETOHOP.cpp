/*

	Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập 
	
	K của tập các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê 
	
	theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, 
	
	và tổ hợp sau lớn hơn tổ hợp trước).

Input

	Dòng đầu ghi hai số N và K.

	Dòng thứ 2 ghi N số của mảng A[]. 
	
	Các giá trị không quá 1000.

	Dữ liệu đảm bảo số phần tử khác nhau của 
	
	A[] không quá 20 và K không quá 10.

Output

	Ghi ra lần lượt các tổ hợp tìm được, 
	
	mỗi tổ hợp trên một dòng.

Ví dụ

Input               Output

8 3

2 4 4 3 5 1 3 4     1 2 3

                    1 2 4

                    1 2 5

                    1 3 4

                    1 3 5

                    1 4 5

                    2 3 4

                    2 3 5

                    2 4 5

                    3 4 5
*/

#include <bits/stdc++.h>

using namespace std;

int a[1005], b[1005];
int sz = 1;
int n, k;

void Back(int i)
{
	for (int j = a[i - 1] + 1; j <= sz - k + i; j++)
	{
		a[i] = j;
		if (i == k)
		{
			for (int i = 1; i <= k; i++)
			{
				cout << b[a[i]] << " ";
			}
			cout << "\n";
		}
		else
			Back(i + 1);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	for (auto x : s)
	{
		b[sz++] = x;
	}
	--sz;
	Back(1);
}