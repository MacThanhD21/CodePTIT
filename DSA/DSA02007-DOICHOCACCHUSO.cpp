/*
    Cho số tự nhiên K và xâu ký tự các chữ số S.  

    Nhiệm vụ của bạn là đưa ra số lớn nhất bằng 

    cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. 

    Ví dụ K =3 và S = “1234567” ta được “7654321”.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.

    T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.


Input               Output

3

4
1234567             7654321

3
3435335             5543333

2
1034                4301

*/


#include <bits/stdc++.h>

using namespace std;

/*
- Idea : + với mỗi vị trí i , tìm thằng lớn nhất sau vị trí i
         + Đảo s[i] với s[pos] vừa tìm được và giảm k
*/

void back(string s, int k)
{

    for (int i = 0; i < s.size(); i++)
    {
        if (k == 0)
            break;

        char maxx = s[s.size() - 1]; // giả sử cái thằng cuối cùng là lớn nhất thì nếu trước nó có phần tư lớn hơn cả nó thì phải đảo phân tử lớn hơn đó lên trên đầu tiên
        int posMax = s.size() - 1;   // còn nếu nó đích thị là phần tử lớn nhất thì cứ việc đổi lên đầu thôi

        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] >= maxx)
            {
                maxx = s[j];
                posMax = j;
            }
        }
        if (maxx > s[i])
        {
            swap(s[posMax], s[i]);
            k--;
        }
    }
    cout << s << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        back(s, k);
    }
}