

/*

    Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. 
    
    Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là 
    
    các xâu viết đúng. Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất 
    
    các ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. 
    
    Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một xâu S viết sai theo nguyên tắc kể trên.

    T, S thòa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤100000.
    
Output:

    Đưa kết quả trên một dòng.
Ví dụ:

Input           Output

2

[]][][          2

[][][]          0


*/

#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    string s;
    cin >> s;
    stack<int> st;
    int res = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '[')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
            {
                int j = i;
                while (s[j] == ']')
                    j++;
                swap(s[i], s[j]);
                res += j - i;
                st.push(i);
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}