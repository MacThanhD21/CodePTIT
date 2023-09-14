/*

	Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các 

	hoán vị của 1, 2, .., N theo thứ tự ngược. 

	Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

Input:

	Dòng đầu tiên đưa vào số lượng test T.

	Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là 
	
	một số tự nhiên N được viết trên một dòng.

	T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input			Output

2

2				21 12 

3				321 312 231 213 132 123       

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define faster()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

int n;
int a[100], visited[100];

void ou()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void Back(int i)
{
	for (int j = n; j >= 1; j--)
	{
		if (!visited[j])
		{
			a[i] = j;
			visited[j] = true;
			if (i == n)
				ou();
			else
				Back(i + 1);
			visited[j] = false;
		}
	}
}

int main()
{
	faster();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Back(1);
		cout << "\n";
	}
}