
/*

    Tại một cây rút tiền ATM thế hệ mới, Tý muốn rút ra W đồng. Các tờ tiền trong máy ATM có mệnh giá từ 1000, 2000, 3000, 5000, 1000*10, 2000*10, 3000*10, 5000*10, …, 1000*10c, 2000*10c, 3000*10c, 5000*10c.

    Chiếc máy ATM đã được tối ưu hóa sao cho số lượng tờ tiền đưa ra cho khách hàng là nhỏ nhất.

    Các bạn hãy thử tính xem Tý sẽ nhận được bao nhiêu tờ tiền? Và có bao nhiêu cách thỏa mãn?

Input

    Số đầu tiên là số lượng bộ test T (T ≤ 1000).

    Mỗi test gồm 2 dòng:

    Dòng thứ nhất chứa số nguyên W.

    Dòng thứ hai chứa số nguyên c.

Output

    Với mỗi test, hãy in ra số lượng tờ tiền nhỏ nhất

    mà máy ATM sinh ra và số tổ hợp các tờ tiền khác nhau

    thỏa mãn tổng giá trị của chúng bằng W.

    Nếu không có đáp án, in ra số 0 trên một dòng.

Ví dụ:

Input           Output

4

2000            1 1

1

7000            2 1

1

1500            0

1

110000          3 2

1


Subtask 1: 30% số test đầu tiên, c ≤ 5, W ≤ 109.

Subtask 2: 70% số test còn lại, c ≤ 15, W ≤ 1018.

Giải thích test 4: 2 cách tìm được là: 50000+50000+10000 và 50000+30000+30000

*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

ll M[4] = {1000, 2000, 3000, 5000};
ll n;
int c;
vector<ll> X, Y;

void reset()
{
    X.clear();
    Y.clear();
}
void init()
{
    int x = 0;
    while (x <= c)
    {
        for (int i = 0; i < 4; i++)
        {
            ll a = M[i] * pow(10, x);
            X.push_back(a);
        }
        x++;
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> c;
        reset();
        if (n % 1000 != 0)
            cout << 0 << endl;
        else
        {
            init();
            reverse(X.begin(), X.end());
            vector<pair<ll, ll>> M;
            ll cnt1 = 0;
            for (auto x : X)
            {
                M.push_back({x, n / x});
                cnt1 += n / x;
                n %= x;
            }
            ll cnt2 = 1;
            ll y = 1;
            for (int i = c; i >= 0; i--)
            {
                vector<pair<ll, ll>> N;
                for (auto x : M)
                {
                    if (to_string(x.first).length() - 4 == i)
                    {
                        N.push_back(x);
                    }
                }

                ll a = pow(10, i);
                ll b = INT_MAX, c = INT_MAX;
                ll m = 5000 * a, n = 3000 * a, p = 1000 * a, q = 2000 * a;
                for (auto x : N)
                {
                    if (x.first == m || x.first == p)
                        b = min(b, x.second);
                }
                for (auto x : N)
                {
                    if (x.first == n || x.first == p)
                        c = min(c, x.second);
                }
                if (b + c >= 1)
                    cnt2 *= (b + c + 1);
            }
            cout << cnt1 << " " << cnt2 << "\n";
        }
    }
}

/*

import math

M = [1000, 2000, 3000, 5000]

def reset():
    X.clear()
    Y.clear()

def init():
    x = 0
    while x <= c:
        for i in range(4):
            a = M[i] * 10**x
            X.append(a)
        x += 1

t = int(input())
for _ in range(t):
    n = int(input())
    c = int(input())
    reset()
    if n % 1000 != 0:
        print(0)
    else:
        init()
        X.reverse()
        M = []
        cnt1 = 0
        for x in X:
            M.append((x, n // x))
            cnt1 += n // x
            n %= x

        cnt2 = 1
        y = 1
        for i in range(c, -1, -1):
            N = [x for x in M if len(str(x[0])) - 4 == i]
            a = 10**i
            b, c = math.inf, math.inf
            m, n, p, q = 5000 * a, 3000 * a, 1000 * a, 2000 * a
            for x in N:
                if x[0] == m or x[0] == p:
                    b = min(b, x[1])
            for x in N:
                if x[0] == n or x[0] == p:
                    c = min(c, x[1])
            if b + c >= 1:
                cnt2 *= (b + c + 1)
        
        print(cnt1, cnt2)

*/