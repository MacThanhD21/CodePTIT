/*
    Cho mảng các số nguyên A[] gồm N phần tử. Hãy chia mảng số nguyên A[] 

    thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau. 

    Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. 

    Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test. 

    Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; 
    
    dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.

    T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.

Output:

    Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0.

Input           Output

2

5 3
2 1 4 5 6       1

5 3
2 1 5 5 6       0

*/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 3;

int n, k, s;
int a[maxN];
bool vs[maxN];
int found;

void Back(int i, int pos, int sum, int cnt)
{
    for (int j = pos; j <= n; j++)
    {
        if (!found && !vs[j])
        {

            vs[j] = true;
            if (i == n)
            {
                if (sum + a[j] == s && cnt + 1 == k)
                    found = 1;
            }

            else if (i < n && sum + a[j] < s)
                Back(i + 1, j + 1, sum + a[j], cnt);
            else if (i < n && sum + a[j] == s)
                Back(i + 1, 1, 0, cnt + 1);

            vs[j] = false;
        }
    }
}

void solve()
{
    cin >> n >> k;
    memset(vs, false, sizeof(vs));
    found = false;
    s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % k != 0)
    {
        cout << 0 << "\n";
        return;
    }
    else
    {
        s /= k;
        // cout << SUM << "\n";
        Back(1, 1, 0, 0);
        cout << found << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int TEST = 1;
    cin >> TEST;
    for (int test = 1; test <= TEST; test++)
    {
        solve();
    }
}