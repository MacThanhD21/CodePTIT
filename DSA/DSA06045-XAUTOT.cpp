
/*

    Xâu đối xứng là xâu mà khi ta đảo ngược thứ tự của 
    
    xâu thì nhận lại được xâu cũ.

    Xâu tốt là xâu mà mỗi ký tự của nó thuộc về ít nhất 1 
    
    xâu đối xứng có độ dài lớn hơn 1.

    Ví dụ: AABBAA,  AABA,.. là các xâu tốt.

    Giá sử cho xâu s chỉ có 2 ký tự A và B. Hãy đếm số xâu con 
    
    là xâu tốt trong s ( Xâu con là hợp các phần tử liền kề nhau của xâu gốc ).

Input:

    Dòng đầu là số ký tự của s ( Không vượt quá 105)

    Dòng thứ 2 là xâu S chỉ gồm các ký tự A và B

Ouput

    Ghi ra kết quả đếm được

Ví dụ

Input               Output

7

BABBAAB             13

6

BAABBA              8
*/

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long
#define p(x) pair<x, x>
#define v(x) vector<x>
#define FORD(i, l, r) for (int i = l; i < r; i++)
#define FORE(i, l, r) for (int i = r - 1; i >= l; i--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define sz size();
#define all(M) M.begin(), M.end()
#define f first
#define s second
#define pb push_back
#define pf push_font

int main()
{
    int n;
    string s;
    cin >> n >> s;
    ll res = 0, tmp = 1;
    FORD(i, 1, n)
    if (s[i] == s[i - 1])
        tmp++, res += i - (tmp <= i);
    else
        res += i - tmp, tmp = 1;
    cout << res << endl;
    return 0;
}