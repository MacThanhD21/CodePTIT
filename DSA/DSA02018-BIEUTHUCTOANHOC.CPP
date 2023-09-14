/*

    Cho 5 số nguyên dương A, B, C, D, E. Bạn có thể hoán vị các phần tử cho nhau,

    hãy đặt các dấu biểu thức +, -, * sao cho biểu thức sau đúng:

    [[[A o(1) B] o(2) C] o(3) D] o(4) E = 23

    Trong đó: o(1) … o(4) là các phép toán +, -, *.

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.

Output:

    Với mỗi test, in ra đáp án tìm được,

    mỗi xâu in ra trên một dòng.

Ví dụ:

Input               Output

3

1 1 1 1 1           NO

1 2 3 4 5           YES

2 3 5 7 11          YES

*/

/*------------------------THAM KHẢO------------------------------------*/

// https://code.ptit.edu.vn/student/question/DSA02018
// BIỂU THỨC TOÁN HỌC

#include <bits/stdc++.h>
using namespace std;

vector<int> a(5);
vector<vector<int>> boSo;
vector<vector<int>> boDau;
vector<int> dau(4);
vector<int> so(5);
vector<bool> vs(5, false);

void TrySo(int i)
{
    if (i == 5)
    {
        boSo.push_back(so);
        return;
    }
    for (int j = 0; j < 5; ++j)
    {
        if (!vs[j])
        {
            vs[j] = true;
            so[i] = a[j];
            TrySo(i + 1);
            vs[j] = false;
        }
    }
}

void TryDau(int i)
{
    if (i == 4)
    {
        boDau.push_back(dau);
        return;
    }
    for (int j = 1; j <= 3; ++j)
    {
        dau[i] = j;
        TryDau(i + 1);
    }
}

int cal(int a, int b, int o)
{
    switch (o)
    {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return a * b;
    }
}

bool check(vector<int> so, vector<int> dau)
{
    return cal(cal(cal(cal(so[0], so[1], dau[0]), so[2], dau[1]), so[3], dau[2]), so[4], dau[3]) == 23;
}

void testCase()
{
    boSo.clear();
    boDau.clear();
    for (int &i : a)
        cin >> i;
    TrySo(0);
    TryDau(0);
    for (auto i : boSo)
    {
        for (auto j : boDau)
        {
            if (check(i, j) == true)
            {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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