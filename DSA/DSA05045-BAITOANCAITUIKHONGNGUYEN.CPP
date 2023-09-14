
/*

    Một trong những bài toán kinh điển của lý thuyết tổ hợp là Bài toán cái túi.

    Bài toán được phát biểu như sau: Một nhà thám hiểm cần đem theo một cái túi

    trọng lượng không quá W. Có N đồ vật cần đem theo. Đồ vật thứ i có trọng lượng

    A[i], có giá trị sử dụng C[i]. Nhiệm vụ của bạn là hãy tìm cách đưa đồ vật vào túi

    cho nhà thám hiểm sao cho tổng giá trị sử dụng các đồ vật trong túi là lớn nhất.

    Giả thiết với mỗi đồ vật, ta có thể chia nhỏ chúng ra thành nhiều phần khác nhau

    (Fraction Knapsack).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào

    hai số N, W tương ứng với số lượng đồ vật và trọng lượng túi;

    phần thứ 2 đưa vào 2*N số tương ứng với trọng lượng đồ vật

    A[i] và giá trị sử dụng C[i] của mỗi đồ vật.

    T, N, W, A[i], C[i]  thỏa mãn ràng buộc:

    1≤T≤100;  1≤N, W≤100; 1≤A[i], C[i]≤100.

Output:

    Đưa ra kết quả mỗi test theo từng dòng,

    in ra 2 chữ số sau dấu phảy.
Ví dụ:

Input               Output

2

3 50                240.00
60 10
100 20
120 30

2 50                160.00
60 10
100 20

*/

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
bool comp(ii a, ii b)
{
    return 1.0 * a.first / a.second > 1.0 * b.first / b.second;
}
void solve()
{
    int n, b;
    cin >> n >> b;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, comp);
    double ans = 0;
    for (int i = 0; i < n && b > 0; i++)
    {
        if (b - a[i].second >= 0)
            ans += 1.0 * a[i].first, b -= a[i].second;
        else
        {
            ans += 1.0 * b * a[i].first / a[i].second;
            b = 0;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}