
/*

    Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu
    
    biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. 
    
    Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. 
    
    Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

Input: 

    Dòng đầu ghi số bộ test, mỗi bộ test có 
    
    một dòng chứa số nguyên n (1 ≤ n ≤ 106) — 
    
    tổng các chữ số của số may mắn cần tìm.

Output: 

    In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. 
    
    Nếu không tồn tại số thỏa mãn, in ra -1.

Ví dụ:

Input           Output

2

11              47

10              -1

*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> ans;

    while (N > 0)
    {
        if (N % 7 == 0)
        {
            int tmp = N / 7;
            while (tmp--)
            {
                ans.push_back(7);
                N -= 7;
            }
        }
        else
        {
            ans.push_back(4);
            N -= 4;
        }
    }
    if (N == 0)
    {
        for (auto x : ans)
        {
            cout << x;
        }
        cout << "\n";
    }
    else
        cout << "-1\n";
    // cout << "\n";
}

int main()
{

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}