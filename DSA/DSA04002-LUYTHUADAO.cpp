/*
	Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N.

	Đưa ra kết quả của bài toán dưới dạng modulo với 10^9 + 7.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng kế tiếp đưa vào các bộ test.

	Mỗi bộ test gồm là số N được ghi trên một dòng.

	T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1010.

Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input			Output

2
2				4
12				864354781

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

const int mod = 1e9 + 7;

ll powMod(ll n, ll p)
{
	if (p == 1)
		return n;
	ll res = powMod(n, p >> 1) % mod;
	res = (res * res) % mod;
	if (p % 2 == 1)
		res = (res * n) % mod;
	return res % mod;
}

int main()
{
	IO();
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll m = n;
		ll tmp = 0;
		while (m)
		{
			tmp = tmp * 10 + (m % 10);
			m /= 10;
		}
		cout << powMod(n, tmp) << "\n";
	}
}

/*

mod = 10**9 + 7

def powMod(n, p):
    if p == 1:
        return n
    res = powMod(n, p // 2) % mod
    res = (res * res) % mod
    if p % 2 == 1:
        res = (res * n) % mod
    return res % mod

t = int(input())
for _ in range(t):
    n = int(input())
    m = n
    tmp = 0
    while m:
        tmp = tmp * 10 + (m % 10)
        m //= 10
    result = powMod(n, tmp)
    print(result)

*/