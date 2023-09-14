
/*

   Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
   
   Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

Input:

   Dòng đầu tiên đưa vào T là số lượng bộ test.

   Những dòng tiếp theo đưa vào các bộ test. 
   
   Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số 
   
   |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; 
   
   Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.

   T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

   Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) 
   
   của mỗi test theo khuôn dạng của ví dụ dưới đây.

Ví dụ:

Input:                                       Output:

1

6  9  1

1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4          1 2 5 4 6 3
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

void BFS(int u)
{
   queue<int> q;
   q.push(u);
   visited[u] = true;
   while (!q.empty())
   {
      int u = q.front();
      q.pop();
      cout << u << " ";
      for (int x : adj[u])
      {
         if (!visited[x])
         {
            q.push(x);
            visited[x] = true;
         }
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
         // adj[y].pb(x);
      }
      for (int i = 1; i <= v; i++)
      {
         sort(all(adj[i]));
      }
      BFS(u);
      cout << "\n";
      for (int i = 1; i <= v; i++)
      {
         adj[i].clear();
      }
      memset(visited, false, sizeof(visited));
   }
}