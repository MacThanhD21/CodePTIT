/*

    Cho tập từ ghi trong trừ điển dic[] và một bảng hai chiều A[M][N] các ký tự.

    Hãy tạo nên tất cả các từ có mặt trong từ điển dic[] bằng cách nối các ký tự

    kề nhau trong mảng A[][]. Chú ý, phép nối các ký tự kề nhau trong mảng A[][]

    được thực hiện theo 8 hướng nhưng không có phần tử A[i][j] nào được lặp lại.

    Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”, “QIUZ”, “GO”} và mảng A[][]

    dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”


G           I           Z

U           E           K

Q           S           E


Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào

    ba số K, M, N tương ứng với số từ của từ điển dic[],

    số hàng và số cột của ma trận ký tự A[M][N];

    dòng tiếp theo đưa vào K từ của từ điển dic[];

    dòng cuối cùng đưa vào các phần tử A[i][j].

    T, K, M, N thỏa mãn ràng buộc: 1≤T ≤10; 1≤K≤100; 1≤ M, N ≤3.

Output:

    Đưa ra theo thứ tự tăng dần các từ có mặt trong

    từ điển dic[] được tạo ra từ ma trận A[][]. Đưa ra -1

     nếu không thể tạo ra từ nào thuộc dic[] từ A[][].

Input                       Output

1
4  3  3                     GEEKS QUIZ
GEEKS FOR QUIZ GO
G I Z

U E K

Q S E

*/

/*------------------------THAM KHẢO------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int k, n, m;
map<string, int> dic;
vector<vector<string>> a;
vector<vector<bool>> vs;
vector<string> res;

void Try(int i, int j, string s)
{
    if (dic[s])
        res.push_back(s);
    for (int z = 0; z < 8; ++z)
    {
        int x = i + dr[z];
        int y = j + dc[z];
        if (x >= 0 && x < n && y >= 0 && y < m && vs[x][y] == 0)
        {
            vs[x][y] = 1;
            Try(x, y, s + a[x][y]);
            vs[x][y] = 0;
        }
    }
}

void testCase()
{
    dic.clear();
    res.clear();
    cin >> k >> n >> m;
    while (k--)
    {
        string s;
        cin >> s;
        dic[s] = 1;
    }
    a.clear();
    a.resize(n, vector<string>(m));
    vs.clear();
    vs.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vs[i][j] = 1;
            Try(i, j, a[i][j]);
            vs[i][j] = 0;
        }
    }
    if (res.empty())
    {
        cout << -1;
        return;
    }
    for (string i : res)
        cout << i << " ";
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