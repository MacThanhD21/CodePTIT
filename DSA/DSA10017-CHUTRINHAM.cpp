

/*

    Cho đồ thị có trọng số G=<V, E> được biểu diễn dưới dạng danh sách cạnh 
    
    trọng số âm hoặc dương. Hãy viết chương trình xác định xem đồ thị 
    
    có chu trình âm hay không.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai số 
    
    |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; 
    
    |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w 
    
    tương ứng với một cạnh cùng với trọng số canh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra 1 hoặc 0 theo từng dòng của mỗi test tương ứng 
    
    với đồ thị có hoặc không có chu trình âm.

Ví dụ:

Input:                  Output:

2

3  3                    0

1  2 -1

2  3  4

3  1 -2

3  3                    1

1  2 -1

2  3  2

3  1 -2

*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int>

/* 
    BellmanFord :

 + có thể áp dụng cho đồ thị có cạnh âm
 + không thể áp dụng trong trường hợp đồ
   thị có chu trình âm
*/
struct edge
{
    int x, y, w;
};

int n, m;
vector<edge> adj;

void init()
{
    cin >> n >> m;
    adj.clear();
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge tmp = {x, y, z};
        adj.pb(tmp);
    }
}

void BellmanFord(int s)
{
    int d[n + 1];
    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : adj)
        {
            int u = it.x, v = it.y, w = it.w;

            if (d[u] != 1e9 && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
    bool check = false;
    for (auto it : adj)
    {
        int u = it.x, v = it.y, w = it.w;
        if (d[u] != 1e9 && d[v] > d[u] + w)
        {
            d[v] = d[u] + w;
            check = true;
            break;
        }
    }
    if (check)
        cout << "1\n";
    else
        cout << "0\n";
}
int main()
{

    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        BellmanFord(1);
    }
}