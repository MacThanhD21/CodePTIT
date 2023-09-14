
/*

    Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. 
    
    Hãy in ra danh sách cạnh tương ứng của G.

Input

    Dòng đầu tiên ghi số N là số đỉnh (1<N<50)

    N dòng tiếp theo mỗi dòng ghi 1 danh sách kề 
    
    lần lượt theo thứ tự từ đỉnh 1 đến đỉnh N

Output: 

    Ghi ra lần lượt từng cạnh của 
    
    đồ thị theo thứ tự tăng dần.

Ví dụ

Input               Output

3
                    
2 3                 1 2

1 3                 1 3

1 2                 2 3

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();
    vector<int> G[1005];

    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        string tmp;
        stringstream ss(s);
        while (ss >> tmp)
        {
            G[i].push_back(stoi(tmp));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(G[i].begin(), G[i].end());
        for (auto x : G[i])
        {
            if (x > i)
            {
                cout << i << " " << x << "\n";
            }
        }
    }
}