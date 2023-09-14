
/*

    Cho dãy số A[] gồm có N phần tử. Một bộ 3 số (a, b, c) 
    
    được gọi là bộ ba số Pytago nếu như a^2 + b^2 = c^2.

    Nhiệm vụ của bạn là kiểm tra xem có tồn tại bộ ba số 
    
    Pytago trong dãy số A[] hay không?

Input:

    Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

    Mỗi test gồm số nguyên N (1≤ N ≤5000).

    Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10^9).

Output: 

    Với mỗi test, in ra trên một dòng “YES” nếu tìm được, 
    
    và “NO” trong trường hợp ngược lại.

Ví dụ:

Input               Output

2

5

3 1 4 6 5           YES

3

1 1 1               NO

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A, A + N);
        bool found = false;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int c = sqrt(A[i] * A[i] + A[j] * A[j]);
                if (c * c == A[i] * A[i] + A[j] * A[j])
                {
                    if (binary_search(A, A + N, c))
                    {
                        found = true;
                        cout << "YES\n";
                        break;
                    }
                }
            }
        }
        if (!found)
        {
            cout << "NO\n";
        }
    }
}
