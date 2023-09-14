

/*
    Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D
     
    là số các chữ số của một số. Nhiệm vụ của bạn là tìm số nhỏ nhất 
    
    thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 
    
    Mỗi bộ test là bộ 2 số S và D được viết trên một dòng.

    T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤ S,D≤1000.
Output:

    Đưa ra kết quả mỗi test theo từng dòng. 
    
    Nếu không có đáp án, in ra -1.
    
Ví dụ:

Input           Output

2
9 2             18
20 3            299

*/


#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int s, d;
    cin >> s >> d;
    if (s > 9 * d)
    {
        cout << -1;
        return;
    }
    int a[d] = {1};
    s--; // 100...
    for (int i = d - 1; i >= 0; --i)
    {
        int x = min(s, 9 - a[i]);
        a[i] += x;
        s -= x;
    }
    for (int i = 0; i < d; ++i)
    {
        cout << a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        testCase();
        cout << "\n";
    }
    return 0;
}