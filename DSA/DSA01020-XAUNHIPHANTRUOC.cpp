/*

	Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. 

	Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. 

	Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. 

	Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

Input:

	Dòng đầu tiên đưa vào số lượng test T.

	Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.

	T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.

Output:

	Đưa	 ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input			Output

2

010101			010100

111111			111110
*/	


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define faster()                 \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

void solve(string s)
{
	int i = s.size() - 1;
	while (i >= 0 && s[i] == '0')
	{
		s[i] = '1';
		--i;
	}
	if (i != -1)
	{
		s[i] = '0';
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	faster();
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		solve(s);
	}
}