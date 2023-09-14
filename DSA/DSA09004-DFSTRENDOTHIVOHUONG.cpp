/*
  Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
  
  Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

Input:

   Dòng đầu tiên đưa vào T là số lượng bộ test.

   Những dòng tiếp theo đưa vào các bộ test. 
   
   Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào 
   
   ba số |V|, |E| tương ứng với số đỉnh và số cạnh của 
   
   đồ thị, và u là đỉnh xuất phát; |E| dòng tiếp theo đưa 
   
   vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

   T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

   Đưa ra danh sách các đỉnh được duyệt theo thuật toán 
   
   DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
Ví dụ:

Input:               Output:

1

6 9 5

1 2

1 3

2 3

2 4                  5 3 1 2 4 6

3 4

3 5

4 5

4 6

5 6
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO()                         \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
   cout << u << " ";
   visited[u] = true;
   for (auto v : adj[u])
   {
      if (!visited[v])
      {
         DFS(v);
      }
   }
}

int main()
{
   IO();
   int t;
   cin >> t;
   while (t--)
   {
      int v, e, u;
      cin >> v >> e >> u;
      for (int i = 1; i <= e; i++)
      {
         int x, y;
         cin >> x >> y;
         adj[x].pb(y);
         adj[y].pb(x);
      }
      for (int i = 1; i <= v; i++)
      {
         sort(all(adj[i]));
      }
      DFS(u);
      cout << "\n";
      for (int i = 1; i <= v; i++)
         adj[i].clear();
      memset(visited, false, sizeof(visited));
   }
}