
/*

	Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. 
	
	Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) 
	
	có tổng bằng S cho trước.

Input: 

	Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, 
	
	dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và 
	
	S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng 
	
	của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  

	Với mỗi bộ test, nếu bài toán vô nghiệm 
	
	thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:

Input						Output

2

5 6
1 2 4 3 5					YES

10 15
2 2 2 2 2 2 2 2 2 2			NO	

*/


#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n, a[N][N];
vector<string> v;
bool check = false;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		int F[k + 1] = {0};
		memset(F, 0, sizeof(F));
		F[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = k; j >= a[i]; j--)
			{
				if (F[j - a[i]])
				{
					F[j] = 1;
				}
			}
		}
		if (F[k])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}