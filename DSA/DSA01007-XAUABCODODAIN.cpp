/*
	Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. 
	
	Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB 
	
	có độ dài n.

Input:

	Dòng đầu tiên đưa vào số lượng test T.

	Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.

	T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.

Output:

	Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.

Ví dụ:

Input			Output

2				

2				AA AB BA BB

3				AAA AAB ABA ABB BAA BAB BBA BBB
*/


#include <bits/stdc++.h>
using namespace std;

int n;
string a[1005];
bool ok;

void ktao()
{
	for (int i = 1; i <= n; i++)
		a[i] = 'A';
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i] == "B")
	{
		a[i] = "A";
		--i;
	}
	if (i == 0)
		ok = false;
	else
		a[i] = 'B';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ok = true;
		ktao();
		while (ok)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << a[i];
			}
			cout << " ";
			sinh();
		}
		cout << endl;
	}
	return 0;
}