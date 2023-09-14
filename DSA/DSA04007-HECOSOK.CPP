/*

    Cho hai số A, B ở hệ cơ số K. Hãy tính tổng hai số đó ở hệ cơ số K.

Input: 

    Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test ghi 3 số K,A,B.

    (2≤K≤10; A và B nếu biểu diễn trong hệ cơ số 10 đều nhỏ hơn 109)

Output: 

    In ra tổng của A và B trong hệ cơ số K

Ví dụ:

Input           Output

1
2 1 10          11

*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
    using namespace std;
string chuyen(int k, int n)
{
    string res = "";
    while (n)
    {
        res = to_string(n % k) + res;
        n /= k;
    }
    return res;
}
int chuyen1(int k, string n)
{
    int res = 0;
    for (int i = 0; i < n.length(); i++)
    {
        res = res * k + n[i] - '0';
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string a, b;
        cin >> a >> b;
        int x = chuyen1(k, a);
        int y = chuyen1(k, b);
        int res = x + y;
        cout << chuyen(k, res) << "\n";
    }
}

/*

def chuyen(k, n):
    res = ""
    while n:
        res = str(n % k) + res
        n //= k
    return res

def chuyen1(k, n):
    res = 0
    for i in range(len(n)):
        res = res * k + int(n[i])
    return res

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        a, b = input().split()
        x = chuyen1(k, a)
        y = chuyen1(k, b)
        res = x + y
        print(chuyen(k, res))

*/