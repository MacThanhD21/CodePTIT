
/*

	Trong một buổi học toán, giáo viên viết 2 số nguyên, 
	
	A và B, và yêu cầu Tèo thực hiện phép cộng. 
	
	Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng 
	
	cậu ta chép các con số một cách không chính xác. 
	
	Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  
	
	Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

Input: 

	Có một dòng chứa hai số nguyên dương 
	
	A và B ( 1 ≤ A, B ≤ 1 000 000).

Output: 

	In ra 2 số nguyên cách nhau một dấu cách, 
	
	tổng nhỏ nhất và lớn nhất có thể nhận được.

Ví dụ:

Test 1					Test 2					Test 3

Input:					Input:					Input:

11 25					1430 4862				16796 58786

Ouput:					Ouput:					Ouput:
						
36 37					6282 6292				74580 85582

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

ll Max6(string s)
{
	ll ans = 0;
	for (char &x : s)
	{
		if (x == '5')
			x = '6';
		ans = ans * 10 + (x - '0');
	}
	return ans;
}

ll Min5(string s)
{
	ll ans = 0;
	for (char &x : s)
	{
		if (x == '6')
			x = '5';
		ans = ans * 10 + (x - '0');
	}
	return ans;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string a, b;
	cin >> a >> b;
	cout << Min5(a) + Min5(b) << " " << Max6(a) + Max6(b) << "\n";
}
