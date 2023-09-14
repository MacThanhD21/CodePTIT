

/*

	Cho một cây có N đỉnh và gốc tại đỉnh 1. Mỗi nút lá có chức năng tổng hợp 
	
	chất dinh dưỡng, đồng thời lan truyền năng lượng cũng như các chất dinh dưỡng 
	
	cho nút cha của nó để thực hiện quá trình tổng hợp.

	Quá trình lan truyền năng lượng sẽ làm tăng giá trị dinh dưỡng lên 1. 
	
	Tức là nếu một nút tổng hợp được giá trị dinh dưỡng bằng V, 
	
	sẽ giúp cho nút cha của nó sẽ tổng hợp được giá trị dinh dưỡng bằng V+1. 
	
	Nếu một nút cha có nhiều nút con, giá trị dinh dưỡng của nó bằng tổng của 
	
	giá trị dinh dưỡng của các nút con gửi lên.

	Biết rằng mỗi nút lá ban đầu tổng hợp được chất dinh dưỡng có giá trị 1. 
	
	Nhiệm vụ của bạn là hãy xác định xem mỗi nút của cây tổng hợp được bao nhiêu giá trị dinh dưỡng?

Input:

	Dòng đầu tiên là số lượng đỉnh N (N <= 200 000).

	Dòng tiếp theo gồm N-1 số nguyên, a[2], a[3], …, a[N] 
	
	lần lượt là cha của các nút 2, 3, …, N.

Output: 

	In ra N số nguyên, số nguyên thứ i cho biết 
	
	giá trị dinh dưỡng mà nút i tổng hợp được.

Test ví dụ:

Test 1					Test 2

Input:					Input:

3						5

1 1						1 2 2 4

Output:					Output:
	
5 1 1					13 8 1 3 1

*/

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[200005];

long long total[200005];
long long spread[200005];

void dfs(int u){
	for(auto x : adj[u]){
		dfs(x);
		spread[u] += spread[x] + 1; // lan truy?n
//		cout << spread[u] << " ";
		total[u] += total[x];
	}
	total[u] += spread[u];
}

void solve(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		adj[x].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		total[i] = 1;
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << total[i] << " ";
	}
	cout << "\n";
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}