

/*

    Cho dãy số A[] có n phần tử là các số nguyên dương. 
    
    Hãy sắp xếp dãy số theo thuật toán sắp xếp nổi bọt. 
    
    Nhưng yêu cầu in ra lần lượt các bước chạy của thuật 
    
    toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

Chú ý: thuật toán sắp xếp nổi bọt có thể kết thúc khi 

tất cả dãy đã sắp xếp, không còn cặp số cạnh nhau nào sai thứ tự.

Input

    Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm 2 dòng:

    Dòng đầu ghi số n (1 < n < 100)

    Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 1000)

Output

    Ghi ra lần lượt các bước thuật toán theo thứ tự ngược
    
    (xem ví dụ mẫu để hiểu rõ hơn).

Ví dụ

Input               Output

1

6

4 1 3 9 8 5         Buoc 2: 1 3 4 5 8 9
                    Buoc 1: 1 3 4 8 5 9

*/

#include <bits/stdc++.h>

using namespace std;

bool ok = false;
vector<int> v[10005];

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        ok = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ok = true;
            }
        }
        if (ok)
        {
            for (int k = 0; k < n; k++)
            {
                v[i + 1].push_back(a[k]);
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (v[i].empty())
            continue;
        else
        {
            cout << "Buoc " << i << ": ";
            for (auto x : v[i])
                cout << x << " ";
            cout << "\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int &x : a)
            cin >> x;
        bubbleSort(a, n);
        for (int i = 0; i < 10005; i++)
        {
            v[i].clear();
        }
    }
}