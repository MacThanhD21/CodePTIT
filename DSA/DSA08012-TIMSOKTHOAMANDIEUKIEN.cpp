
/*

    Cho hai số nguyên dương L, R. Hãy đưa ra số các số K trong khoảng

    [L, R] thỏa mãn điều kiện:

    Tất cả các chữ số của K đều khác nhau.

    Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5.

    Ví dụ với L = 4, R = 13 ta có 5 số thỏa mãn yêu cầu là 4, 5, 10, 12, 13,

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Dòng tiếp theo đưa vào các bộ test.

    Mỗi bộ test được là một cặp L, R được viết trên một dòng.

    T, L, R thỏa mãn ràng buộc: 1≤T≤100; 0≤L≤R≤105.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input               Output

2

4  13               5

100  1000           100

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair<int, int>

vector<int> v;

bool check(int n)
{
    int b[1005] = {0};
    while (n)
    {
        int m = n % 10;
        n /= 10;
        b[m]++;
        if (b[m] == 2)
            return false;
    }
    return true;
}

void init()
{
    queue<int> Q;
    for (int i = 1; i <= 5; i++)
    {
        Q.push(i);
    }
    while (1)
    {
        int tmp = Q.front();
        Q.pop();
        v.push_back(tmp);
        if (tmp >= 1e5)
            break;
        for (int i = 0; i <= 5; i++)
        {
            int res = tmp * 10 + i;
            if (check(res))
            {
                Q.push(res);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    init();
    while (T-- > 0)
    {
        int L, R;
        cin >> L >> R;

        int ans = 0;
        for (auto x : v)
        {
            if (x >= L && x <= R)
                ++ans;
        }
        // cout << "\n";
        cout << ans << "\n";
        // v.clear();
    }
}