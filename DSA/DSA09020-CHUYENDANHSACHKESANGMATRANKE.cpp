
/*

   Cho đơn đồ thị vô hướng có n đỉnh dưới dạng danh sách kề.

   Hãy biểu diễn đồ thị bằng ma trận kề.

Input: 

   Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 ≤  n ≤  1000). 
   
   n dòng tiếp theo, dòng thứ i chứa các số nguyên là các đỉnh kề với đỉnh i.  

Output:  
   
   Ma trận kề của đồ thị.

Ví dụ:

Input          Output

3

2 3            0 1 1

1 3            1 0 1

1 2            1 1 0

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, x, a[N + 1][N + 1];

int main()
{
   cin >> n;
   memset(a, 0, sizeof(a));
   for (int i = 0; i < n; i++)
   {
      string s;
      getline(cin, s);
      string tmp;
      stringstream ss(s);
      while (ss >> tmp)
      {
         int u = stoi(tmp);
         a[i][u] = a[u][i] = 1;
      }
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cout << a[i][j] << " ";
      }
      cout << "\n";
   }
}
