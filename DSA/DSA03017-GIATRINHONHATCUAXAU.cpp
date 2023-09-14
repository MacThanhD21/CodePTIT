
/*

	Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương
	
	số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá trị nhỏ nhất của 
	
	xâu S sau khi thực hiện K lần loại bỏ ký tự.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm hai phần: phần thứ nhất là số K; 
	
	phần thứ hai là một xâu ký tự S được viết trên một dòng.

	T, S, K thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤K≤1000.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input			Output

2
2				6
ABCCBC

2				2
AAAB

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		string s;
		cin >> s;
		map<char, ll> mp;
		for (int i = 0; i < s.size(); i++)
			mp[s[i]]++;
		priority_queue<ll> q;
		for (auto it : mp)
			q.push(it.second);
		while (k--)
		{
			ll tmp = q.top();
			--tmp;
			q.pop();
			q.push(max(tmp, 1ll * 0));
		}
		ll ans = 0;
		while (!q.empty())
		{
			ans += 1ll * q.top() * q.top();
			q.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}
