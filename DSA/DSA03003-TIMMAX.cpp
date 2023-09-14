
/*

	Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là tìm bằng cách sắp đặt
	
	lại các phần tử trong mảng. Chú ý, kết quả của bài toán có thể rất 
	 
	lớn vì vậy bạn hãy đưa ra kết quả lấy modulo với 109+7.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 

	Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số 
	
	phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] 
	
	tương ứng với các phần tử của mảng A[]; các số được viết 
	
	cách nhau một vài khoảng trống.

	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i] ≤107.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
	
Ví dụ:

Input				Output

2

5					40
5 3 2 4 1

3					8
1 2 3

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

const int N = 2e7 + 5;
const int mod = 1e9 + 7;

int n, a[N];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += (a[i] * i);
			sum %= mod;
		}
		cout << sum << "\n";
	}
}
