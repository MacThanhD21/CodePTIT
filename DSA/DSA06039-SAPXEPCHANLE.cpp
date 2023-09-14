
/*
	Cho dãy số a[] có n phần tử, đánh số từ 1 đến n. 
	
	Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần, 
	
	các phần tử ở vị trí chẵn theo thứ tự giảm dần.

Input

	Dòng đầu tiên ghi số n, không quá 105

	Dòng thứ 2 ghi n số của dãy a[] (a ≤ a[i] ≤ 109)

Output

	Ghi ra dãy số kết quả trên một dòng

Ví dụ

Input				Output

4

1 2 3 4				1 4 3 2

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> M(n), A, B;
	for (int i = 0; i < n; i++)
	{
		cin >> M[i];
		if (i % 2 == 0)
			A.push_back(M[i]);
		else
			B.push_back(M[i]);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			cout << A[a++] << " ";
		else
			cout << B[b++] << " ";
	}
}