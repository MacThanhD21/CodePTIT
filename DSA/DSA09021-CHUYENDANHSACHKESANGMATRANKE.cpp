
/*

   Ma trận kề A của một đồ thị vô hướng là một ma trận chỉ có các số 0 hoặc 1 
   
   trong đó A[i][j] = 1 có ý nghĩa là đỉnh i kề với đỉnh j (chỉ số tính từ 1).

   Danh sách kề thì liệt kê các đỉnh kề với đỉnh đó theo thứ tự tăng dần.

   Hãy chuyển biểu diễn đồ thị từ dạng ma trận kề sang dạng danh sách kề.

Input: 

   Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 < n ≤ 1000). 

   n dòng tiếp theo, mỗi dòng có n số nguyên có giá trị 0 và 1 mô tả ma trận kề của đồ thị.

Output:  

   Gồm n dòng, dòng thứ i chứa các số nguyên là đỉnh có nối với đỉnh i 

   và được sắp xếp tăng dần. Dữ liệu đảm bảo mỗi đỉnh có kết nối với ít nhất 1 đỉnh khác.

Ví dụ:

Input          Output

3

0 1 1          2 3

1 0 1          1 3

1 1 0          1 2

*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define se second
#define fi first
#define all(x) x.begin(), x.end()

const int N = 1010;
int n, x, a[N + 1][N + 1];
vector<int> adj[N + 1];

int main()
{
   cin.tie(0)->sync_with_stdio(0);

   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cin >> a[i][j];
      }
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         if (a[i][j] == 1)
         {
            adj[i].pb(j);
         }
      }
   }
   for (int i = 1; i <= n; i++)
   {
      sort(all(adj[i]));
   }
   for (int i = 1; i <= n; i++)
   {
      for (auto x : adj[i])
         cout << x << " ";
      cout << "\n";
   }
}
