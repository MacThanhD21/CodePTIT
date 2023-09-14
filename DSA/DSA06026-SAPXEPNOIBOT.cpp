

/*

	Hãy thực hiện thuật toán sắp xếp nổi bọt trên dãy N số nguyên.

	Ghi ra các bước thực hiện thuật toán.

Dữ liệu vào:

	Dòng 1 ghi số N (không quá 100).

	Dòng 2 ghi N số nguyên dương (không quá 100).

Kết quả:

	Ghi ra màn hình từng bước thực hiện thuật toán.

	Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.

Ví dụ:

Input				Output

4

5 3 2 7				Buoc 1: 3 2 5 7

					Buoc 2: 2 3 5 7

*/

#include <bits/stdc++.h>

using namespace std;

int t = 1;
bool ok;
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		ok = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				ok = true;
			}
		}
		if (ok)
		{
			cout << "Buoc " << i + 1 << ": ";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << "\n";
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int &x : a)
		cin >> x;
	bubbleSort(a, n);
}