
/*

    Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. 
    
    Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : 
    
    ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó 
    
    lên đầu dãy hoặc về cuối dãy.

    Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.

Input

    Dòng đầu tiên ghi 1 số n: số lượng phần tử của dãy a (1 ≤ n ≤ 100000)

    Dòng tiếp theo gồm n số từ 1 đến n theo thứ tự ngẫu nhiên
Output

    Một số nguyên duy nhất là số bước tối thiểu 
    
    cần thực hiện để hoàn thành việc sắp xếp.
    
Ví dụ

Input               Output

5
4 1 2 5 3           2

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ms(a) memset(a, 0, sizeof(a));
#define all(v) v.begin(), v.end()
#define endl "\n"
#define pb push_back

const int N = 2e7 + 5;
const int mod = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }
    int ans = 1;
    int ewans = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (b[i] < b[i + 1])
        {
            ++ans;
        }
        else
            ans = 1;
        ewans = max(ewans, ans);
    }
    cout << n - ewans << "\n";
}


/*

n = int(input())
a = list(map(int, input().split()))
b = [0] * (n + 1)

for i in range(1, n + 1):
    b[a[i]] = i

ans = 1
ewans = 1

for i in range(1, n):
    if b[i] < b[i + 1]:
        ans += 1
    else:
        ans = 1
    ewans = max(ewans, ans)

print(n - ewans)

*/