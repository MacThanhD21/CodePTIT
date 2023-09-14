
/*

    Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3

    của số Y (X= Y3). Cho số nguyên dương N, nhiệm vụ của bạn là tìm

    số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N.

    Ví dụ số 4125 ta có kết quả là 125 = 53.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là một số tự nhiên N được viết trên một dòng.

    T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1018.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.

    Nếu không tìm được đáp án in ra -1.
    
Ví dụ:

Input           Output

2
4125            125
976             -1

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long int ll;

bool ktra(string a, string b)
{
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return j == b.length();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long res = 0;
        bool ok = false;
        for (int i = 1; i <= 100; i++)
        {
            long long x = i * i * i;
            if (ktra(s, to_string(x)))
            {
                ok = true;
                res = x;
            }
        }
        if (!ok)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
}