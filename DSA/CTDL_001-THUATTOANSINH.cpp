/*
	Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân 

	đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím). 

	Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n. 

	Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

	Ví dụ với n = 4 ta tìm được 4 xâu nhị phân thuận nghịch như dưới đây.

			0                      0                      0                      0         

			0                      1                      1                      0         

			1                      0                      0                      1         

			1                      1                      1                      1

Ví dụ

Input	Output
4	    0 0 0 0

        0 1 1 0

        1 0 0 1

        1 1 1 1

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define faster() \
ios::sync_with_stdio(false);\
cin.tie(0);\
cout.tie(0);

int n, a[100];
bool check(){
	int l = 1, r = n;
	while(l < r){
		if(a[l] != a[r]) return false;
		else ++l; --r;
	}
	return true;
}
void out(){
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			if(check())
			   out();
		} 
		else Try(i + 1);
	}
}
int main(){
	faster();
	cin >> n;
	Try(1);
}