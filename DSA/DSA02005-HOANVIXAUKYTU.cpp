

/*
	Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. 

	Hãy đưa ra tất cả các hoán vị của xâu ký tự S. 

	Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T.

	Những dòng tiếp theo đưa vào các bộ test. 
	
	Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.

	T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;

Output:

	Đưa ra kết quả mỗi test theo từng dòng.


Input				Output

2
AB					AB BA

ABC					ABC ACB BAC BCA CAB CBA 

*/


#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	do
	{
		cout << s << " ";
	} while (next_permutation(s.begin(), s.end()));
}

int main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
}