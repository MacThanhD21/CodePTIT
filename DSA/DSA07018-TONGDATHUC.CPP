/*

    Cho hai đa thức có bậc không quá 10000 (chỉ viết ra các phần tử có hệ số khác 0).

    Hãy sử dụng danh sách liên kết đơn để viết chương trình tính tổng hai đa thức đó.

Dữ liệu vào:

    Dòng đầu ghi số bộ test. Mỗi bộ test có hai dòng,

    mỗi dòng ghi một đa thức theo mẫu như trong ví dụ.

    Số phần tử của đa thức không quá 20.

    Chú ý: Bậc của các hạng tử luôn theo thứ tự giảm dần,

    trong đa thức chỉ có phép cộng và luôn được viết

    đầy đủ hệ số + số mũ (kể cả mũ 0).

Kết quả:

    Ghi ra một dòng đa thức tổng tính được (theo mẫu như ví dụ)

Ví dụ:

Input                                       Output

1

3*x^8 + 7*x^2 + 4*x^0
                                            3*x^8 + 11*x^6 + 16*x^2 + 2*x^1 + 7*x^0
11*x^6 + 9*x^2 + 2*x^1 + 3*x^0

*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

void solve()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);

    set<int> se;

    for (auto &x : s)
    {
        if (x == '+')
            x = ' ';
    }
    for (auto &x : t)
    {
        if (x == '+')
            x = ' ';
    }

    stringstream ss1(s), ss2(t);
    string token1, token2;

    vector<pair<int, int>> M, N;
    while (ss1 >> token1)
    {
        int i = token1.find("*x^");
        M.push_back({stoi(token1.substr(0, i)), stoi(token1.substr(i + 3))});
        se.insert(stoi(token1.substr(i + 3)));
    }
    while (ss2 >> token2)
    {
        int i = token2.find("*x^");
        N.push_back({stoi(token2.substr(0, i)), stoi(token2.substr(i + 3))});
    }

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < N.size(); j++)
        {
            if (M[i].second == N[j].second)
            {
                M[i].first += N[j].first;
            }
        }
    }

    for (auto x : N)
    {
        if (se.count(x.second) == 0)
        {
            M.push_back(x);
        }
    }

    sort(M.begin(), M.end(), comp);
    for (int i = 0; i < M.size() - 1; i++)
    {
        cout << M[i].first << "*x^" << M[i].second << " + ";
    }
    cout << M[M.size() - 1].first << "*x^" << M[M.size() - 1].second << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
}
