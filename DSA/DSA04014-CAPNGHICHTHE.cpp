
/*


    Cho mảng A[] gồm N phần tử. Ta gọi cặp nghịch thế của mảng A[]

    là số các cặp i, j sao cho i<j và A[i]>A[j]. Đối với mảng đã được

    sắp xếp thì số cặp nghịch thế bằng 0. Mảng đã sắp theo thứ tự giảm dần

    có số đảo ngược cực đại. Nhiệm vụ của bạn là hãy đưa ra số cặp nghịch thế

    của mảng A[] gồm N phần tử.

Input:

    Dòng đầu tiên đưa vào số lượng bộ test T.

    Những dòng kế tiếp đưa vào các bộ test.

    Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào

    số N tương ứng với số phần tử của mảng A[]; phần thứ 2

    là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.

    T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤107; 1≤A[i]≤1018.

Output:

    Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input           Output

2
5               3
2 4 1 3 5

5               10
5 4 3 2 1


*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

ll merge(ll M[], ll N[], int left, int mid, int right)
{
    int i, j, k;
    ll res = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (M[i] <= M[j])
        {
            N[k++] = M[i++];
        }
        else
        {
            N[k++] = M[j++];
            res += mid - i;
        }
    }
    while (i <= mid - 1)
        N[k++] = M[i++];
    while (j <= right)
        N[k++] = M[j++];
    for (i = left; i <= right; i++)
        M[i] = N[i];

    return res;
}
ll _mergeSort(ll M[], ll N[], int left, int right)
{
    ll mid, res = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        res += _mergeSort(M, N, left, mid);
        res += _mergeSort(M, N, mid + 1, right);
        res += merge(M, N, left, mid + 1, right);
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll N[100000];
        ll M[100000];
        for (int i = 0; i < n; i++)
        {
            cin >> M[i];
        }
        ll res = _mergeSort(M, N, 0, n - 1);
        cout << res << "\n";
    }
}

/*

def merge(M, N, left, mid, right):
    i, j, k = left, mid, left
    res = 0
    while i <= mid - 1 and j <= right:
        if M[i] <= M[j]:
            N[k] = M[i]
            i += 1
        else:
            N[k] = M[j]
            j += 1
            res += mid - i
        k += 1

    while i <= mid - 1:
        N[k] = M[i]
        i += 1
        k += 1

    while j <= right:
        N[k] = M[j]
        j += 1
        k += 1

    for i in range(left, right + 1):
        M[i] = N[i]

    return res

def _mergeSort(M, N, left, right):
    res = 0
    if right > left:
        mid = (right + left) // 2
        res += _mergeSort(M, N, left, mid)
        res += _mergeSort(M, N, mid + 1, right)
        res += merge(M, N, left, mid + 1, right)
    return res

t = int(input())
for _ in range(t):
    n = int(input())
    M = list(map(int, input().split()))
    N = [0] * n
    res = _mergeSort(M, N, 0, n - 1)
    print(res)

*/