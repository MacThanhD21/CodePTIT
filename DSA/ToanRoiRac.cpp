#define MAX 100
int a[MAX][MAX];   // Ma trận kề
int n;             // Số đỉnh của đồ thị
bool visited[MAX]; // Mảng đánh dấu các đỉnh đã được duyệt

// Hàm duyệt đồ thị theo chiều sâu
void DFS(int u)
{
    visited[u] = true; // Đánh dấu đỉnh u đã được duyệt
    cout << u << " ";  // In ra đỉnh u
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] && !visited[v])
        {           // Nếu có cạnh nối từ u tới v và v chưa được duyệt
            DFS(v); // Duyệt đỉnh v
        }
    }
}

#define MAX = 100;
int a[MAX][MAX];   // Ma trận kề của đồ thị
bool visited[MAX]; // Mảng đánh dấu các đỉnh đã được duyệt
int n;             // số đỉnh của đồ thị

void BFS(int u)
{
    queue<int> Q;
    visited[u] = true;
    Q.push(u);
    while (!Q.empty())
    {
        int s = Q.front(); // Lấy đỉnh đầu tiên trong hàng đợi
        cout << s << " ";  // In ra đỉnh vừa lấy
        Q.pop();           // Xóa đỉnh khỏi hàng đợi
        for (int i = 1; i <= n; i++)
        {
            if (a[s][i] && !visited[i]) // Kiểm tra xem có cạnh nối từ đỉnh s đến đỉnh i hay không
            {
                visited[i] = true; // Đánh dấu đã duyệt đỉnh i
                Q.push(i);         // Thêm đỉnh i vào hàng đợi
            }
        }
    }
}

#define MAX 100
int a[MAX][MAX];   // ma trận kề
bool visited[MAX]; // mảng đánh dấu các đỉnh đã được thăm hay chưa
int n;             // số đỉnh của đồ thị

void DFS(int u)
{
    visited[u] = true; // Đánh dấu đỉnh u đã được duyệt
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] && !visited[v]) // Nếu đỉnh v chưa được duyệt và có cạnh nối với u
        {
            DFS(v); // Duyệt đỉnh v
        }
    }
}

int TPLT_DFS()
{
    int coun = 0; // Khởi tạo số thành phần liên thông
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) // Nếu đỉnh i chưa được duyệt
        {
            coun++; // Tăng số thành phần liên thông lên 1
            DFS(i); // Duyệt các đỉnh liên thông với đỉnh i
        }
    }
    return coun; // Trả về số thành phần liên thông của đồ thị
}

#define MAX 100
int n, a[MAX][MAX]; // số đỉnh của đồ thị và ma trận kề
bool visited[MAX];  // mảng đánh dấu các đỉnh đã được thăm hay chưa

void BFS(int u)
{
    queue<int> Q; // khởi tạo hàng đợi
    Q.push(u);
    visited[u] = true; // đẩy đỉnh u vào hàng đợi và đánh dấu đã duyệt
    while (!Q.empty()) // duyệt chừng nào hàng đợi chưa rỗng
    {
        int u = Q.front();
        Q.pop(); // lấy ra đỉnh hàng đợi và duyệt ma trận kề của đỉnh đó
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == false)
            {
                Q.push(v);
                visited[v] = true; // đẩy đỉnh vào hàng đợi và đánh dấu đã duyệt
            }
        }
    }
}

int TPLT_BFS()
{
    int coun = 0; // Khởi tạo số thành phần liên thông
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) // Nếu đỉnh i chưa được duyệt
        {
            coun++; // Tăng số thành phần liên thông lên 1
            BFS(i); // Duyệt các đỉnh liên thông với đỉnh i
        }
    }
    return coun; // Trả về số thành phần liên thông của đồ thị
}

#define MAX = 100;

bool visited[MAX];
int n, a[MAX][MAX], parent[MAX]; // ma trận kề và mảng lưu đỉnh cha

void DFS(int u)
{
    visited[u] = true;           // đánh dấu đã duyệt đỉnh u
    for (int v = 1; v <= n; v++) // duyệt ma trận kề của đỉnh u
    {
        if (a[u][v] == 1 && !visited[v]) // nếu v chưa thăm và có đường đi từ u -> v thì duyệt đỉnh v
        {
            parent[v] = u; // cập nhật đỉnh cha cho đỉnh v
            DFS(v);
        }
    }
}

void T_DFS()
{
    for (int i = 1; i <= n; i++) // duyệt tất cả các đỉnh
    {
        if (!visited[i]) // nếu đỉnh nào chưa được thăm
        {
            DFS(i); // thì DFS đến đỉnh đó để tìm cây khung
        }
    }

    cout << "Edges of MST:"
         << "\n";
    // In ra cây khung
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " - " << i << "\n";
    }
}

#define MAX = 100;
int n, a[MAX][MAX], parent[MAX]; // Số đỉnh của đồ thị và ma trận kề
bool visited[MAX];               // Mảng đánh dấu các đỉnh đã được duyệt

void BFS(int u)
{
    queue<int> Q;      // Khởi tạo hàng đợi
    visited[u] = true; // Đánh dấu đỉnh u đã duyệt
    Q.push(u);         // Đẩy đỉnh u vào hàng đợi
    while (!Q.empty())
    {
        int u = Q.front(); // Lấy đỉnh đầu tiên trong hàng đợi
        cout << u << " ";  // In ra đỉnh vừa lấy
        Q.pop();           // Xóa đỉnh khỏi hàng đợi
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] && !visited[v]) // Kiểm tra xem có cạnh nối từ đỉnh s đến đỉnh i hay không
            {
                visited[v] = true; // Đánh dấu đã duyệt đỉnh i
                Q.push(v);         // Thêm đỉnh i vào hàng đợi
                parent[v] = u;     // cập nhật đỉnh cha cho đỉnh v
            }
        }
    }
}

void T_BFS()
{
    for (int i = 1; i <= n; i++) // duyệt tất cả các đỉnh
    {
        if (!visited[i]) // nếu đỉnh nào chưa được thăm
        {
            BFS(i); // thì DFS đến đỉnh đó để tìm cây khung
        }
    }

    cout << "Edges of MST:"
         << "\n";
    // In ra cây khung
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " - " << i << "\n";
    }
}

#define MAX = 100;
int n, a[MAX][MAX]; // Số đỉnh của đồ thị và ma trận kề
bool visited[MAX];

int isEulerian()
{
    int odd = 0; // Biến odd để đếm số đỉnh bậc lẻ

    for (int i = 1; i <= n; i++)
    {
        int degree = 0;
        for (int j = 1; j <= n; j++)
        {
            degree += a[i][j];
        }
        if (degree % 2 != 0)
        {
            odd++; // nếu bán bậc của các đỉnh là lẻ thì odd tăng thêm 1
        }
    }
    if (odd == 0)
    {
        return 1; // => đồ thị là Euler
    }
    if (odd == 2)
    {
        return 2; // => đồ thị là Nửa Euler
    }
    return 0; // => Không có chu trình
}

void Fleury(int u, vector<int> &CE)
{
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] == 1)
        {
            a[u][v] = a[v][u] = 0; // đánh dấu cạnh đã duyệt
            Fleury(v, a, n, path); // đệ quy đến cạnh kề với đỉnh u để duyệt tiếp
        }
    }
    // Khi mà đỉnh u cô lập thì sẽ thêm vào chu trình CE
    CE.push_back(u);
}

void EULER()
{
    if (isEulerian() == 0)
    {
        cout << "Khong ton tai chu trinh / duong di Euler!"
             << "\n";
        return;
    }
    // chu trình / đường đi của đồ thị nửa Euler
    else if (isEulerian() == 2)
    {
        int start = 0; // tìm đỉnh đầu tiên có bậc lẻ để duyệt chu trình và
                       // kết thúc ở đỉnh bậc lẻ còn lại.
        for (int i = 1; i <= n; i++)
        {
            int degree = 0;
            for (int j = 1; j <= n; j++)
            {
                degree += a[i][j];
            }
            if (degree % 2 != 0)
            {
                start = i; // đánh dấu đỉnh đó lại
                break;
            }
        }
        vector<int> CE;    // Khởi tạo chu trình CE
        Fleury(start, CE); // Thuật toán bắt đầu từ đỉnh vừa tìm được

        reverse(path.begin(), path.end()); // Lật ngược chu trình lại

        // In ra chu trình
        cout << "Chu trinh/duong di Euler la: ";

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }

    // chu trình / đường đi của đồ thị Euler
    else if (isEulerian() == 1)
    {
        vector<int> CE;
        Fleury(1, CE); // bắt đầu từ đỉnh 1

        reverse(path.begin(), path.end()); // Lật ngược chu trình

        // In ra chu trình
        cout << "Chu trinh/duong di Euler la: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
}

#define MAX = 100;
int n, m, a[MAX][MAX]; // ma trận trọng số
int d[MAX];            // Mảng lưu khoảng cách từ đỉnh u -> mọi đỉnh

void DIJKTRA(int u)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9; // khởi tạo khoảng cách từ đỉnh u -> các đỉnh còn lại là vô cùng
    }
    d[u] = 0; // Đỉnh u có khoảng cách bắt đầu = 0

    // Hàng đợi ưu tiên mà ở đỉnh luôn lưu khoảng cách nhỏ nhất lưu cặp {distance, đỉnh}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    Q.push({0, u}); // Đẩy đỉnh u vào trong hàng đợi ưu tiên để bắt đầu duyệt

    while (!Q.empty())
    {
        // Lấy ra khoảng cách nhỏ nhất và đỉnh hiện tại để xét
        int distance = Q.top().first, u = Q.top().second;
        Q.pop();

        if (distance > d[u]) // - Điều kiện if này có nghĩa là trong hàng đợi nó đã có phiên bản tốt hơn
            continue;        //  (đường đi tốt hơn) rồi nên continue

        for (int v = 1; v <= n; ++v)
        {
            int W = a[u][v];         // lấy ra trọng số của đỉnh u,v
            if (d[v] > distance + W) // Điều kiện để cập nhật lại khoảng cách từ đỉnh u -> v
            {
                d[v] = distance + W; // Cập nhật lại khoảng cách từ đỉnh u -> v
                Q.push({d[v], v});   // Đẩy lại vào trong hàng đợi để cập nhật cho đến hết.
            }
        }
    }
    // In ra khoảng cách từ đỉnh u -> mọi đỉnh
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << "\n";
    }
}

// floyd

#define MAX = 100;
int n, a[MAX][MAX], d[MAX][MAX];

void FLOYD()
{
    // Khởi tạo ma trận d[][] ban đầu bằng ma trận trọng số a[][].
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = a[i][j];
        }
    }

    // Duyệt lần lượt qua tất cả các đỉnh từ 1 đến n, và cập nhật lại ma trận d[][].
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j]) // Nếu đường đi từ đỉnh i -> j > đường đi từ i -> k + đường đi từ k -> j thì sẽ cập nhật
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

#define MAX 100
int n, m, a[MAX][MAX];
bool visited[MAX];

void PRIM(int u)
{
    long long d = 0; // Cây khung cực tiểu nhỏ nhất

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // min_heap : lưu min ở đỉnh hàng đợi
    Q.push({0, u});                                                                    // Queue lưu cặp trọng số và đỉnh cần xét

    visited[u] = true; // đánh dấu đỉnh s
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();

        int W = top.first;  // top.first : trọng số
        int u = top.second; // top.second : đỉnh của đồ thị

        if (visited[top.second])
            continue;

        d += W; // cộng trọng số vào cây khung cực tiểu

        visited[top.second] = true; // Đánh dấu đỉnh đã duyệt

        // duyệt ma trận trọng số
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v])
            {                         // Tiếp tục duyệt các đỉnh kề chưa được thăm của đỉnh u
                Q.push({a[u][v], v}); // và đẩy vào trong hàng đợi cặp {trọng số, đỉnh kề}
            }
        }
    }
    // In ra cây khung cực tiểu
    cout << d << "\n";
}

struct edge
{
    int u, v, w;
};

vector<edge> adj; // sử dụng vector struct để lưu

#define MAX = 100;
int n, m;
int parent[MAX], sz[MAX];
int a[MAX][MAX];

// Khoi tao
void init()
{
    cin >> n >> m;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= m; v++)
        {
            if (a[u][v] != 0)
            {
                adj.push_back({u, v, a[u][v]});
                // u : đỉnh đầu
                // v : đỉnh cuối
                // a[u][v] : trọng số
            }
        }
    }
    // Khởi tạo 2 mảng để sử dụng cho Disjoint Set Union
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

// DSU : Disjoint Set Union dùng để nối 2 đỉnh xem có tạo thành chu trình hay không.

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    // Nếu thấy 2 đỉnh cần nối có cùng cha , thì không thể nối
    if (x == y)
        return false;
    // Ngược lại ta có thể nối 2 đỉnh đó với nhau
    if (sz[x] <= sz[y])
    {
        parent[x] = y;
        sz[x] += sz[y];
    }
    else
    {
        sz[y] += sz[x];
        parent[y] = x;
    }
    return true;
}

// Sắp xếp theo trọng số giảm dần
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void KRUSKAL()
{
    long long ans = 0;               // Cây khung có tổng trọng số nhỏ nhất
    vector<edge> MST;                // Khởi tạo cây khung MST
    sort(begin(adj), end(adj), cmp); // Sắp xếp theo thứ tự trọng số giảm dần
    for (int i = 0; i < m; i++)
    {

        // Nếu MST.size() == n - 1 thì break , tức là đã xây dựng được cây
        // khung kết nối với tất cả các đỉnh của đồ thị, có n - 1 cạnh
        if (MST.size() == n - 1)
            break;

        int x = adj[i].u, y = adj[i].v, z = adj[i].w;
        // Ta sẽ nối 2 đỉnh x với y
        // + Nếu nối được ta sẽ cộng trọng số vào ans và thêm nó vào cây khung
        // + Nếu không ta sẽ nhảy sang cạnh tiếp theo
        if (Union(x, y))
        {
            ans += z;
            MST.push_back(adj[i]);
        }
    }
    // Nếu MST.size() != n - 1 thì đồ thị KHÔNG liên thông

    // In ra cây khung nhỏ nhất
    cout << ans << "\n";
    for (auto it : MST)
    {
        cout << it.u << " " << it.v << " " << it.w << "\n";
    }
}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX = 100;
int c[MAX][MAX], f[MAX][MAX]; // ma trận trọng số và luồng
int trace[MAX];               // trace[v] = u, u là đỉnh trước v trên đường tăng luồng

bool BFS(int s, int t, int n)
{
    bool visited[MAX];
    memset(visited, false, sizeof(visited));        // reset mảng visited về false hết
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && c[u][v] > f[u][v])
            {
                q.push(v);
                visited[v] = true;
                trace[v] = u; // lưu lại đỉnh trước v trên đường tăng luồng
                if (v == t)
                    return true; // tìm được đường tăng luồng
            }
        }
    }
    return false; // không tìm được đường tăng luồng
}

int Ford_Fulkerson(int s, int t, int n)
{
    int max_flow = 0;
    while (BFS(s, t, n))
    {
        int delta = INT_MAX;
        // Tìm độ lớn của luồng tăng trên đường tăng luồng
        for (int v = t; v != s; v = trace[v])
        {
            int u = trace[v];
            delta = min(delta, c[u][v] - f[u][v]);
        }
        // Tăng luồng trên đường tăng luồng thêm delta
        for (int v = t; v != s; v = trace[v])
        {
            int u = trace[v];
            f[u][v] += delta;
            f[v][u] -= delta;
        }
        max_flow += delta; // cập nhật luồng cực đại
    }
    return max_flow;       // trả về giá trị luồng cực đại
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] += w; // cập nhật trọng số của cạnh (u, v)
    }
    int max_flow = Ford_Fulkerson(s, t, n);
    cout << "Max flow = " << max_flow << endl;
    return 0;
}
