
/*

	Cho mảng đã được sắp xếp A[] gồm N phần tử không có 
	
	hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). 
	
	Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N 
	
	là số phần tử của mảng A[] và số X; dòng tiếp theo 
	
	đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 1≤ A[i]≤1018.

Output:

	Đưa ra vị trí của  floor(X) trong mảng A[] hoặc -1 
	
	nếu không tồn tại floor(X) của mỗi test theo từng dòng.

Ví dụ:

Input					Output

3
7 0						-1
1 2 8 10 11 12 19
7 5						2
1 2 8 10 11 12 19
7 10					4
1 2 8 10 11 12 19

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			auto it = lower_bound(a.begin(), a.end(), k);
			if (it != a.begin())
			{
				--it;
				cout << it - a.begin() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
}


/*

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    for i in range(n):
        idx = -1
        for j in range(i - 1, -1, -1):
            if a[j] >= k:
                idx = j
                break
        print(idx if idx != -1 else -1)

*/