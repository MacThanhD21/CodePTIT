
/*
	Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. 

	Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) 

	theo nguyên tắc:

	Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.

	Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.

	Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

                        
Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 

	Mỗi bộ test gồm hai phần: phần thứ nhất 

	đưa vào số N là kích cỡ của mê cung; 

	dòng tiếp theo đưa vào ma trận nhị phân A[N][N].

	T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.

Output:

	Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển. 

	Đưa ra -1 nếu chuột không đi được đến đích.


Input						Output

2

4

1  0  0  0

1  1  0  1 					DRDDRR

0  1  0  0 

1  1  1  1					

5

1 0 0 0 0

1 1 1 1 1

1 1 0 0 1					DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD

0 1 1 1 1

0 0 0 1 1
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, a[N][N];
vector<string> v;
bool check = false;

void Mouse(int i, int j, string s)
{
	if (i == n - 1 && j == n - 1 && a[i][j])
	{
		v.push_back(s);
		check = true;
	}
	if (i == 0 && j == 0 && a[i][j] == 0)
	{
		check = false;
		return;
	}
	if (i < n - 1 && a[i + 1][j])
	{
		Mouse(i + 1, j, s + "D");
	}
	if (j < n - 1 && a[i][j + 1])
	{
		Mouse(i, j + 1, s + "R");
	}
	if (i < n - 1 && j < n - 1 && a[i + 1][j] == 0 && a[i][j + 1] == 0 || i > n || j > n)
	{
		return;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		Mouse(0, 0, "");
		if (check == false)
		{
			cout << "-1\n";
		}
		else
		{
			sort(v.begin(), v.end());
			for (auto x : v)
			{
				cout << x << " ";
			}
		}
		v.clear();
		cout << "\n";
	}
}