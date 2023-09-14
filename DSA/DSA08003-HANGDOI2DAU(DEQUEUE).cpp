

/*

    Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:

    “PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).

    “PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.

    “POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.

    “PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).

    “PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.

    “POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

Dữ liệu vào:

    Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

    Mỗi truy vấn có dạng như trên.

Kết quả: 

    Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, 
    
    hãy in ra kết quả trên một dòng.

Ví dụ:

Input                           Output

10

PUSHBACK 1

PUSHFRONT 2

PUSHBACK 3                      2

PRINTFRONT                      1

POPFRONT                        3

PRINTFRONT                      NONE

POPFRONT

PRINTBACK

POPFRONT

PRINTBACK

*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> dq;
    int q;
    cin >> q;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "PUSHFRONT")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (op == "PRINTFRONT")
        {
            if (!dq.empty())
            {
                cout << dq.front() << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
        else if (op == "POPFRONT")
        {
            if (!dq.empty())
            {
                dq.pop_front();
            }
        }
        else if (op == "PUSHBACK")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (op == "PRINTBACK")
        {
            if (!dq.empty())
            {
                cout << dq.back() << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
        else if (op == "POPBACK")
        {
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
    }

    return 0;
}
