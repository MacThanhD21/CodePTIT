

/*


    Cho xâu ký tự str. Nhiệm vụ của bạn là tìm số phép chèn tối thiểu

    các ký tự vào str để str trở thành xâu đối xứng. Ví dụ: str =”ab”

    ta có số phép chèn tối thiểu là 1 để trở thành xâu đối xứng “aba” hoặc “bab”.

    Với xâu str=”aa” thì số phép chèn tối thiểu là 0. Với xâu str=”abcd” có số

    phép chèn tối thiểu là 3 để trở thành xâu “dcbabcd”

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test là một xâu ký tự được viết trên một dòng

    T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str)≤40.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input               Output

3
abcd                3
aba                 0
geeks               3

*/

#include <iostream>
#include <cstring>

using namespace std;

int test(string s, int n)
{
    int M[100][100];
    memset(M, 0, sizeof(M));
    for (int i = 0; i < n; i++)
        M[i][i] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                M[i][j] += M[i + 1][j - 1] + 2;
            else
            {
                M[i][j] = max(M[i + 1][j], M[i][j - 1]);
            }
        }
    }
    return n - M[0][n - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << test(s, s.length()) << "\n";
    }
}