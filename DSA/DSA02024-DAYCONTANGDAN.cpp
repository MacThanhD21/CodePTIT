/*

    Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. 

    Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] 
    
    thỏa mãn tính chất tăng dần.

    Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng 
    
    vẫn giữ nguyên thứ tự ban đầu.

    Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, 

    hãy liệt kê theo thứ tự từ điển.

Input

    Dòng đầu ghi số n (không quá 20)

    Dòng thứ 2 ghi n số của dãy a[]. 
    
    Các số khác nhau từng đôi một và có giá trị không quá 100.
Output

    Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.

Ví dụ

Input           Output

4

6 3 7 11        3 11

                3 7

                3 7 11

                6 11

                6 7

                6 7 11

                7 11

*/


#include <bits/stdc++.h>

using namespace std;

const int N = 100;
#define pb push_back

int n;
int a[N], b[N];
vector<string> ans;

vector<int> save;

void back(int i, vector<int> save)
{
    for (int j = i + 1; j <= n; j++)
    {
        if (a[j] > a[i])
        {
            save.push_back(a[j]);
            if (save.size() >= 2)
            {
                string s = "";
                for (auto x : save)
                    s += (to_string(x) + " ");
                ans.pb(s);
            }
            back(j, save);
            save.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> save;
    back(0, save);
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}