
/*

	Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm 
	
	một số có tần số xuất hiện nhiều nhất, yêu cầu lớn hơn N/2 
	
	lần xuất hiện trong dãy số.

Input:

	Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

	Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), 
	
	số lượng phần tử trong dãy số ban đầu.

	Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 1 000 000).

Output: 

	Với mỗi test in ra đáp án của bài toán trên một dòng. 
	
	Nếu không tìm được đáp án, in ra “NO”.

Ví dụ:

Input					Output

2

9

3 3 4 2 4 4 2 4 4		4

8

3 3 4 2 4 4 2 4			NO

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		map<int, int> mp;
		for (int &x : a)
		{
			cin >> x;
			mp[x]++;
		}
		bool ok = false;
		for (auto it : mp)
		{
			if (it.second > n / 2)
			{
				cout << it.first << "\n";
				ok = true;
			}
		}
		if (!ok)
			cout << "NO\n";
	}
}