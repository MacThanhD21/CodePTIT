/*
	Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. 

	Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho 

	tổng các phần tử của dãy con đó đúng bằng K. Các phần tử 

	của dãy số A[] được giả thuyết là nguyên dương và không có 

	các phần tử giống nhau. Ví dụ với dãy con A[] = {5, 10, 15, 20, 25},

	K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai phần: phần thứ nhất 
	
	đưa vào số N là số lượng phần tử của dãy số A[] và số K; 
	
	dòng tiếp theo đưa vào N phần tử của dãy số A[].

	T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.

Output:

	Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn 

	yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi 

	dãy con được bao bởi các ký tự [, ]. Nếu không có dãy con 

	nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.


Input								Output

2
5 50
5  10 15 20  25						[5 10 15 20] [5 20 25] [10 15 25]

8  53
15  22  14  26  32  9  16  8		[8 9 14 22] [8 14 15 16] [15 16 22]


*/


#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, k, a[N];

vector<vector<int>> v;

void Back(int i, int sum, vector<int> a)
{
	for (int j = i; i <= n; j++)
	{
		a.push_back(a[j]);
		sum += a[j];
		if (sum == k)
		{
			v.push_back(a);
		}
		else if (sum < k)
		{
			Back(j, sum, a);
		}
		sum -= a[j];
		a.pop_back();
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		vector<int> a;
		Back(1, 0, a);
		if (!v.size())
		{
			cout << "-1\n";
		}
		else
		{
			for (auto x : v)
			{
				cout << "[";
				for (int i = 0; i < x.size() - 1; i++)
				{
					cout << x[i] << " ";
				}
				cout << x[x.size() - 1] << "] ";
			}
		}
		cout << "\n";
		v.clear();
	}
}