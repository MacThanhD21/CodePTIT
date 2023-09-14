
/*

    Ban đầu cho một queue rỗng. 
    
    Bạn cần thực hiện các truy vấn sau:

    Trả về kích thước của queue

    Kiểm tra xem queue có rỗng không, 
    
    nếu có in ra “YES”, nếu không in ra “NO”.

    Cho một số nguyên và đẩy số nguyên này vào cuối queue.

    Loại bỏ phần tử ở đầu queue nếu queue không rỗng, 
    
    nếu rỗng không cần thực hiện.

    Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.

    Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.

Dữ liệu vào

    Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ theo dạng sau.

    Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000)

    N dòng tiếp theo, mỗi dòng sẽ ghi loại truy vấn như trên, 
    
    với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 106.

Kết quả: 

    In ra kết quả của các truy vấn..

Ví dụ:

Input               Output

1

14

3 1

3 2                 1

3 3                 3

5                   5

6                   2

4

4

4

4

4

3 5

3 6

5

1

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> q;
        int n;
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            if (x == 1)
                cout << q.size() << endl;
            if (x == 2)
            {
                if (q.empty())
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            if (x == 3)
            {
                int y;
                cin >> y;
                q.push(y);
            }
            if (x == 4)
            {
                if (!q.empty())
                    q.pop();
            }
            if (x == 5)
            {
                if (!q.empty())
                    cout << q.front() << endl;
                else
                    cout << -1 << endl;
            }
            if (x == 6)
            {
                if (!q.empty())
                    cout << q.back() << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
    return 0;
}