
/*

	Cho dãy số A[], B[] và C[] là dãy không giảm và có lần lượt N, M, K phần tử. 
	
	Nhiệm vụ của bạn là hãy tìm các phần tử chung của 3 dãy số này.

Input:

	Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

	Mỗi test gồm số nguyên N, M và K (1≤ N, M, K ≤ 100 000).

	Dòng tiếp theo gồm N số nguyên A[i], rồi M số nguyên B[i] và K số nguyên C[i].

	(0 ≤ A[i], B[i], C[i] ≤ 10^9).

Output: 

	Với mỗi test, in ra trên một dòng là đáp án thu được. 
	
	Nếu không tìm được đáp án, in ra “NO”.

Ví dụ:

Input							Output

3

6 5 8							20 80

1 5 10 20 40 80

5 7 20 80 100

3 4 15 20 30 70 80 120

3 5 4							5 5

1 5 5

3 4 5 5 10

5 5 10 20

3 3 3							NO

1 2 3

4 5 6

7 8 9

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m], c[k];
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;
		for (int &x : c)
			cin >> x;
		int i = 0, j = 0, u = 0;
		bool ok = false;
		while (i < n && j < m && u < k)
		{
			if (a[i] == b[j] && a[i] == c[u])
			{
				cout << a[i] << " ";
				++i;
				++j;
				++u;
				ok = true;
			}
			else if (a[i] < b[j])
			{
				++i;
			}
			else if (b[j] < c[u])
			{
				++j;
			}
			else
				++u;
		}
		if (ok == false)
			cout << "NO\n";
		cout << "\n";
	}
}

/*

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    i, j, u = 0, 0, 0
    ok = False
    while i < n and j < m and u < k:
        if a[i] == b[j] and a[i] == c[u]:
            print(a[i], end=" ")
            i += 1
            j += 1
            u += 1
            ok = True
        elif a[i] < b[j]:
            i += 1
        elif b[j] < c[u]:
            j += 1
        else:
            u += 1
    if not ok:
        print("NO")
    print()

*/