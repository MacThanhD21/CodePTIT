
/*

    Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật, 
    
    một số sinh viên D19 CNTT - PTIT quyết định bỏ học, 
    
    đầu tư thuê đất để trồng rau. Mảnh đất thuê là một hình chữ nhật N x M 
    
    (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông. Nhưng chỉ sau đó vài ngày, 
    
    trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập. 
    
    Mảnh đất bỗng biến thành các cái ao. Và sinh viên D19 lại dự định 
    
    chuyển sang nuôi cá. Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu 
    
    cái ao để có thể tính toán nuôi cá cho hợp lý. Hãy giúp các bạn ấy nhé. 
    
    Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. 
    
    Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.

Dữ liệu vào: 

    Dòng1: 2 số nguyên cách nhau bởi dấu cách: N và M. 

    Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất.  

    Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.

Kết quả:  

    Một dòng chứa 1 số nguyên duy nhất là số ao tạo thành.

Input                           Output

10 12

W........WW.

.WWW.....WWW

....WW...WW.

.........WW.

.........W..                    3   

..W......W..

.W.W.....WW.

W.W.W.....W.

.W.W......W.

..W.......W.

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int, int>
#define v vector
#define pb push_back

int n, m;
char a[105][105];
bool vis[105][105];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j)
{
    vis[i][j] = true;

    for (int k = 0; k < 8; k++)
    {
        int I = i + dx[k];
        int J = j + dy[k];
        if (I >= 0 && I < n && J >= 0 && J < m && !vis[I][J] && a[I][J] == 'W')
        {
            dfs(I, J);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        init();

        memset(vis, false, sizeof(vis));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && a[i][j] == 'W')
                {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
}