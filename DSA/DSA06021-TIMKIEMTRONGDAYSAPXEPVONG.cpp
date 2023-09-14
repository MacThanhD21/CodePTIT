

/*

	Một mảng được sắp được chia thành hai đoạn tăng dần 
	
	được gọi là mảng sắp xếp vòng. Ví dụ mảng 
	
	A[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4} là mảng sắp xếp vòng. 
	
	Cho mảng A[] gồm n phần tử, hãy tìm vị trí của phần tử x 
	
	trong mảng A[] với thời gian log(n).

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.
	Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n và x; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
	T, n, A[i], x  thỏa mãn ràng buộc: 1≤T≤100; 1≤N, x, A[i] ≤107.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input							Output

2
10 3
5 6 7 8 9 10 1 2 3 4			9
10 3
1 2 3 4 5 6 7 8 9 10			3

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int a[n + 1];
		int pos = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = n; i >= 1; i--)
		{
			if (a[i] == x)
				pos = i;
		}
		cout << pos << endl;
	}
}