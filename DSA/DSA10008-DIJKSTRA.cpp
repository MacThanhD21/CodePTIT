

/*

    Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng 
    
    danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất 
    
    từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

Input:

    Dòng đầu tiên đưa vào T là số lượng bộ test.

    Những dòng tiếp theo đưa vào các bộ test. 
    
    Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số 
    
    |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; 
    
    |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w 
    
    tương ứng với một cạnh cùng với trọng số canh của đồ thị.

    T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:

    Đưa ra kết quả của mỗi test theo từng dòng. 
    
    Kết quả mỗi test là trọng số đường đi ngắn nhất từ 
    
    đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.

Ví dụ:

Input:                  Output:

1

9  12 1                 0 4 12 19 26 16 18 8 14 

1  2   4

1  8   8

2  3   8

2  8   11

3  4   7

3  6   4

3  9   2

4  5   9

4  6  14

5  6  10

6  7  2

6  9  6


*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(u) u.begin(), u.end()
#define ii pair<int, int> 

// DIJKSTRA : Áp dụng bài toán tìm đường đi ngắn nhất

/*
 - Tạo 1 mảng d[i] : lưu đường đi ngắn nhất từ đỉnh s -> i
 - Tạo 1 hàng đợi ưu tiên lưu pair<kc, đỉnh>
  + Tất cả các đỉnh khởi tạo bằng vô cùng trừ đỉnh gốc
  + Đẩy ({0, s}) vào trong hàng đợi

  + Xử lý trường hợp Nếu khoảng cách hiện tại của nó > khoảng cách đã xét 
    trước đó thì sẽ pop đỉnh đó đi
  + Kiểm tra điều kiện : d[v] > d[u] + w;
  (trong đó : v là đỉnh kề với đỉnh u, w là trọng số đi kèm
   + d[v] : là khoảng cách từ đỉnh s -> v, d[u] tương tự
  )
*/

int n, m, s;
vector<ii> adj[10005];

void init(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        adj[x].pb({y, z});
    }
}

void DiJKSTRA(int s){
    int d[n + 1]; // d[i] : lưu lại khoảng cách ngắn nhất từ đỉnh s -> đỉnh i
    for(int i = 1; i <= n; i++){
        d[i] = 1e9;
    }
    d[s] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, s}); 

    while(!Q.empty()){
        ii top = Q.top(); Q.pop();

        int disTance = top.first, u = top.second;
        if(disTance > d[u])
            continue;
        for(auto it : adj[u]){
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t; cin >> t;
    while(t--){
        init();
        DiJKSTRA(s);
    }
}