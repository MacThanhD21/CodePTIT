
/*

    Bài toán Tháp Hà Nội đã rất nổi tiểng. Bắt đầu có các đĩa xếp chồng lên cột A 

    theo thứ tự kích thước giảm dần, nhỏ nhất ở trên cùng. Cột B và cột C ban đầu 

    không có đĩa nào cả.

    https://ntucoder.net/ckfinder/userfiles/images/HaNoi.png

    Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, 
    
    tuân theo các quy tắc sau:

    Mỗi lần chỉ có thể di chuyển một đĩa.

    Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một cột khác.

    Không được đặt đĩa lên trên đĩa nhỏ hơn.

Input:

    Số tự nhiên  0 < N < 10

Output:

    In ra lần lượt từng bước theo mẫu trong ví dụ. 
    
    Chú ý giữa các chữ cái và dấu -> có khoảng trống.

Ví dụ:

Input       Ouput

3           A -> C

            A -> B

            C -> B

            A -> C

            B -> A

            B -> C

            A -> C
*/


#include <bits/stdc++.h>

using namespace std;

const int N = 100;

#define pb push_back

void back(int n, char a, char b, char c)
{
    if(n==1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    back(n - 1, a, c, b);
    back(1, a, b, c);
    back(n - 1, b, a, c);
}


void solve()
{
    int n; cin >> n;
    back(1, 'A', 'B', 'C');
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}