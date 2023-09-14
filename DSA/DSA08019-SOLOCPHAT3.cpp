
/*
  Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. 
  
  Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

    Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);

    T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
Output:

    Dòng đầu tiên là số lượng số lộc phát tìm được. 
    
    Dòng thứ hai in ra đáp án theo thứ tự giảm dần.

Ví dụ:

Input           Output

2

2               6

                88 86 68 66 8 6

3               14

                888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
const int LOG = 12;


void solve(){
    int n; cin >> n;
    queue<string> Q;
    Q.push("6");
    Q.push("8");
    
    priority_queue<ll> pq;

    while(Q.size()){
    	auto top = Q.front(); Q.pop();
    	
    	if(top.size() > n) break;
    	pq.push(stoll(top));
    	
    	Q.push(top + "6");
    	Q.push(top + "8");
	}
    cout << pq.size() << "\n";
	while(pq.size()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
int main()
{
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--){solve();}
}