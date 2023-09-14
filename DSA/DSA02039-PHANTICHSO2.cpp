
/*

    Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả 
    
    các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn 
    
    hoặc bằng N. Phép hoán vị của một cách được xem là giống nhau. 
    
    Ví dụ với N = 5 ta có kết quả là: 
    
    (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là một số tự nhiên N được viết trên một dòng.

    T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:

    Dòng đầu tiên là số lượng cách phân tích thỏa mãn. 
    
    Dòng tiếp theo liệt kê đáp án theo mẫu ví dụ đã cho.

Ví dụ:

Input           Output

2

4               5

                (4) (3 1) (2 2) (2 1 1) (1 1 1 1)

5               7

                (5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)

*/


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int target;

void back(int N, int sum, vector<int> q)
{
    for (int i = N; i >= 1; i--)
    {
        q.push_back(i);
        sum += i;
        if (sum == target)
        {
            v.push_back(q);
        }
        else if (sum < target)
        {
            back(i, sum, q);
        }
        sum -= i;
        q.pop_back();
    }
}
void solve()
{

    cin >> target;
    vector<int> q;
    back(target, 0, q);
    cout << v.size() << "\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << "(";
        for (int j = 0; j < v[i].size() - 1; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << v[i][v[i].size() - 1] << ") ";
    }
    cout << "\n";
    v.clear();
}

int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}