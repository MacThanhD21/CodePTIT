#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = (int)1e9 + 7;

#define faster()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                   \
    cout.tie(0);                    


void solve(){
    int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	int k; cin >> k;
	for (int i = 0; i < n; i++)
		if (a[i] != k)cout << a[i] << " ";
}

int main(){
    faster();
    int t = 1;
//	cin >> t;
    while(t--){
    	solve();
	}
}