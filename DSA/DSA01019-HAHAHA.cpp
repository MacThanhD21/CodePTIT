/*
	Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. 

	Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

	Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:

	Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A

	Không có hai chữ H nào liền nhau

	Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

Input

	Dòng đầu ghi số bộ test T (không quá 10)

	Mỗi bộ test ghi độ dài N (2 <= N < 16)

Output

	Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, 

	mỗi xâu viết trên một dòng.

Ví dụ:

Input			Output

2				
				HA
2				HAAA
				HAHA
4				
*/

#include <bits/stdc++.h>
using namespace std;

int n, a[100];

bool check()
{
	if (a[1] == 1 && a[n] == 0)
	{
		for (int i = 1; i <= n - 1; i++)
		{
			if (a[i] == 1 && a[i] == a[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void Back(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i == n)
		{
			if (check())
			{
				for (int i = 1; i <= n; i++)
				{
					if (a[i] == 1)
						cout << "H";
					else
						cout << "A";
				}
				cout << "\n";
			}
		}
		else
		{
			Back(i + 1);
		}
	}
}
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Back(1);
	}
}