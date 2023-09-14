/*

    Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. Chỉ có hai chữ số là 0 và 2.

    Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.

    Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày

    hợp lệ chỉ có 2 chữ số 0 và 2.

    Một số chú ý:

    Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.

    Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép.

    Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.

    Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm

    tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự.

    Hãy liệt kê theo đúng thứ tự từ điển tăng dần.

*/
#include <bits/stdc++.h>
using namespace std;

string s(8, '0');
vector<string> res;

void solve()
{
    int d = stoi(s.substr(0, 2));
    int m = stoi(s.substr(2, 2));
    int y = stoi(s.substr(4));
    if (d > 0 && d <= 31 && m > 0 && m <= 12 && y >= 2000)
    {
        string tmp = s;
        tmp.insert(2, 1, '/');
        tmp.insert(5, 1, '/');
        res.push_back(tmp);
    }
}

void Try(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        if (j == 0)
            s[i] = '0';
        else
            s[i] = '2';

        if (i == 7)
            solve();
        else
            Try(i + 1);
    }
}

void testCase()
{
    Try(0);
    sort(res.begin(), res.end());
    for (string i : res)
        cout << i << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    while (T--)
    {
        testCase();
    }
    return 0;
}