
/*

	Cho số tự nhiên N. Hãy tìm cặp số nguyên tố đầu tiên có tổng là N. 
	
	Nếu không tồn tại cặp số nguyên tố có tổng bằng N, hãy đưa ra -1.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test. 
	
	Mỗi bộ test gồm là một số N được ghi trên một dòng.

	T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤106.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Input		Output

2

4			2 2

8			2 5

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
ll prime[1000001];

void sang()
{
	fill(prime, prime + 1000001, 1);
	prime[0] = prime[1] = 0;
	for (ll i = 2; i <= sqrt(1000000); i++)
	{
		if (prime[i])
		{
			for (ll j = i * i; j <= 1000000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	sang();
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll ok = 0;
		for (ll i = 2; i <= n / 2; i++)
		{
			if (prime[i] && prime[n - i])
			{
				ok = 1;
				cout << i << " " << n - i << endl;
				break;
			}
		}
		if (ok == 0)
			cout << -1 << endl;
	}

	return 0;
}
