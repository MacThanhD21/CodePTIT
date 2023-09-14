

/*

	Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số 
	
	A[] =(a0, a1, .., an-1}. Đưa ra phép duyệt theo thứ tự trước 
	
	(preorder) của cây tìm kiếm cân bằng.  Ví dụ với dãy 
	
	A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép 
	
	duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với 
	
	node gốc là 33 : 33, 25, 20, 15, 23, 28, 30, 40, 38, 35, 45.

Input:

	Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).

	Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: 
	
	dòng thứ nhất là số tự nhiên N (N≤106). 
	
	Dòng tiếp theo là N số của mảng A[].
Output:

	Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input														Output

2

11

40  28  45 38  33  15  25  20  23  35  30					30 23 15 20 25 28 38 33 35 40 45

10

1  2  3  4  5  6  7  8  9  10								5 2 1 3 4 8 6 7 9 10

*/

#include<bits/stdc++.h>

using namespace std;

/*
- Cách để đảm bảo cây tìm kiếm cân bằng là mảng đã sort
- Mảng đã sort là tương đương với cây nhị phân tìm kiếm duyệt theo Inorder,
vì chỉ có Inorder mới có thể thỏa mãn tính chất này.
*/

struct node{
	int data;
	node *left, *right;
	
//	node(int u) : data(u), left(nullptr), right(nullptr) {}

	node(int u){
		data = u;
		left = right = NULL;
	}
};

void buil(node *&root, int a[], int l, int r){
	if(l > r){
		return;
	}
	int mid = (l + r) / 2;
	root = new node(a[mid]);
	
	buil(root -> left, a, l, mid - 1);
	buil(root -> right, a, mid + 1, r);
}
void preOrder(node *root){
	if(!root) return;
	
	cout << root -> data << " ";
	
	if(root -> left) preOrder(root -> left);
	if(root -> right) preOrder(root -> right);
}

void solve(){
	int n; cin >> n;
	int a[n];
	node *root = NULL;
	for(auto &x : a) cin >> x;
	
	sort(a, a + n); // thay cho việc xây dựng cây tìm kiếm xong lấy thứ tự inorder (thứ tự tăng dần của cây tìm kiếm)
//	for(auto x : a) cout << x << " "; cout << "\n";
	buil(root, a, 0, n - 1);
	
	preOrder(root);
	cout << "\n";
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}