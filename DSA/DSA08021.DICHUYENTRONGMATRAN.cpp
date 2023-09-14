/*
  Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi 
  
  ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. 
  
  Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí 
  
  A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

Input:

    Dòng đầu tiên đưa vào số lượng test T.

    Dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; 
    
    phần thứ hai là các phần tử của ma trận A[][]; 
    
    các số được viết cách nhau một vài khoảng trống.

    T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.

Output:

    Đưa ra kết quả mỗi test theo từng dòng. 
    
    In ra -1 nếu không tìm được đáp án.

Ví dụ:

Input           Output

1

3  3            2

2  1  2

1  1  1

1  1  1

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ii pair<int, int>
#define ms(a) memset(a, 0, sizeof(a))

int n, m;
int a[2005][2005];
int used[2005][2005];
int coun[2005][2005]; 

int bfs_MaTrix(int i, int j)
{
    queue<ii> Q;
    Q.push({i, j});
    coun[i][j] = 0;
    while (!Q.empty())
    {
        ii top = Q.front();
        Q.pop();

        int i = top.first, j = top.second;

        if (i == n && j == m)
            return coun[i][j];

        if (i + a[i][j] <= n && !used[i + a[i][j]][j])
        {
            coun[i + a[i][j]][j] = coun[i][j] + 1;
            used[i + a[i][j]][j] = true;
            Q.push({i + a[i][j], j});
        }
        if (j + a[i][j] <= m && !used[i][j + a[i][j]])
        {
            coun[i][j + a[i][j]] = coun[i][j] + 1;
            used[i][j + a[i][j]] = true;
            Q.push({i, j + a[i][j]});
        }
    }
    return -1;
}
void solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << bfs_MaTrix(1, 1) << "\n";
    ms(coun);
    ms(used);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t-- > 0)
    {
        solution();
    }
}