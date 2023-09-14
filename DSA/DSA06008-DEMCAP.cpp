
/*


    Cho mảng X[] gồm n phần tử và mảng Y[] gồm m phần tử.

    ãy đếm số các cặp xy>yx, trong đó x€X[] và y€Y[].

    Ví dụ X[] = {2, 1, 6 }, Y[] = {1, 5} ta có kết quả là

    3 cặp (2, 1), (2, 5), (6, 1).

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào T bộ test.

    Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m

    tương ứng với số phần tử của mảng X[] và Y[];

    dòng tiếp theo là n số X[i] của mảng X[];

    dòng cuối cùng là m số của mảng Y[]; các số được

    viết cách nhau một vài khoảng trống.

    T, n, m, X[i], Y[j] thỏa mãn ràng buộc:

    1≤ T ≤100; 1≤ n, m ≤105; 0≤ X[i], Y[j] ≤103.
Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Input           Output

1
3 2
2 1 6           3
1 5

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int test(int x, int Y[], int n, int N[])
{
    if (x == 0)
        return 0;
    if (x == 1)
        return N[0];
    int *i = upper_bound(Y, Y + n, x);
    int a = (Y + n) - i;
    a += (N[0] + N[1]);
    if (x == 2)
        a -= (N[3] + N[4]);

    if (x == 3)
        a += N[2];
    return a;
}

int count1(int X[], int Y[], int m, int n)
{
    int N[5] = {0};
    for (int i = 0; i < n; i++)
        if (Y[i] < 5)
            N[Y[i]]++;
    sort(Y, Y + n);
    int t = 0;
    for (int i = 0; i < m; i++)
        t += test(X[i], Y, n, N);
    return t;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int m[100000], n[100000];
        for (int i = 0; i < a; i++)
            cin >> m[i];
        for (int i = 0; i < b; i++)
            cin >> n[i];
        cout << count1(m, n, a, b) << "\n";
    }
}