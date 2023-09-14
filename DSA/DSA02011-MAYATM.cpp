/*
    Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. 

    Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S 

    (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

Input: 

    Dòng đầu tiên ghi số bộ test T (T<10). Mỗi bộ test gồm 2 số nguyên n và S (S ≤ 109). 
    
    Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: 
    Với mỗi bộ test ghi ra số tờ tiền ít nhất phải trả.

    Nếu không thể tìm được kết quả, in ra -1.


Ví dụ

Input           Output

1

3 5             1

1 4 5

*/


#include <bits/stdc++.h>

using namespace std;

int n, S;
int a[35];
int ans = 0;
bool check;

void back(int i, int sum = 0, int cnt = 0)
{
    if(sum > S || check ==  true) return;
    if(sum == S){
        cout << cnt << "\n";
        check = true;
        return;
    }
    for(int j = i; j <= n; j++){
        back(j + 1, sum + a[j], cnt + 1);
    }
}

void solve()
{
    bool check = false;
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    back(1);
    if(!check) cout << "-1\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}