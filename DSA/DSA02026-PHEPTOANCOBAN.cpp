/*

    Cho một biểu thức trong phạm vi hai chữ số với các phép toán cộng trừ nhân chia.

    Các toán hạng và kết quả đảm bảo là số nguyên dương có hai chữ số,

    nếu có phép chia thì phải thỏa mãn tính chia hết.

    Người ta có thể ẩn đi một số chữ số hoặc phép toán bằng cách điền dấu chấm hỏi (?).

    Nhiệm vụ của bạn là khôi phục các dấu chấm hỏi và in ra phép toán chính xác ban đầu.

    Nếu không thể có kết quả đúng thì ghi ra WRONG PROBLEM!

INPUT

    Dòng đầu ghi số bộ test T (1 ≤ T ≤ 100).

    T dòng tiếp theo, mỗi dòng là một biểu thức có thể có các dấu ?.

    Nếu có thể có nhiều kết quả đúng thì in ra kết quả đầu tiên theo thứ tự từ điển,

    tức là số nhỏ nhất có thể tính từ trái sang phải.

OUTPUT

    Với mỗi bộ test, ghi ra biểu thức đúng tìm được. Hoặc WRONG PROBLEM!

Ví dụ

Input               Output

2

?0 ? 12 = 28        40 - 12 = 28

40 / ?3 = ??        WRONG PROBLEM!

*/

#include <bits/stdc++.h>
using namespace std;

string str;
int sign[2] = {'+', '-'};
bool isOK;

bool isCorrect()
{
    int x = stoi(str.substr(0, 2));
    int y = stoi(str.substr(5, 2));
    int z = stoi(str.substr(10, 2));
    if (x < 10 || y < 10 || z < 10)
    {
        return false;
    }
    if (str[3] == '+')
        return (x + y == z);
    else
        return (x - y == z);
}

void Try(int i)
{
    if (isOK)
        return;
    if (i == str.length())
    {
        if (isCorrect())
        {
            isOK = true;
            cout << str << endl;
        }
        return;
    }
    if (str[i] == '?')
    {
        if (i == 3)
        {
            for (int j = 0; j <= 1; ++j)
            {
                str[i] = sign[j];
                Try(i + 1);
            }
        }
        else
        {
            for (int j = 0; j <= 9; ++j)
            {
                str[i] = j + '0';
                Try(i + 1);
            }
        }
        str[i] = '?';
    }
    else
    {
        Try(i + 1);
    }
}

void testCase()
{
    isOK = false;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '*' or str[i] == '/')
        {
            // không tồn tại phép nhân hay chia giữa 2 số có 2 cs mà ra kết quả là 1 số có 2 cs
            cout << "WRONG PROBLEM!";
            return;
        }
    }
    Try(0);
    if (!isOK)
    {
        cout << "WRONG PROBLEM!";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}