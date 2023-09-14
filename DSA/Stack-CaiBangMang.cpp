#include <iostream>
#define MAX_SIZE 100

using namespace std;

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

// Kiểm tra stack rỗng
bool isEmpty(Stack s) {
    return (s.top == -1);
}

// Kiểm tra stack đầy
bool isFull(Stack s) {
    return (s.top == MAX_SIZE - 1);
}

// Thêm một phần tử vào đỉnh của stack
void push(Stack &s, int x) {
    if (isFull(s)) {
        cout << "Stack is full" << endl;
        return;
    }
    s.arr[++s.top] = x;
}

// Lấy ra và xóa phần tử ở đỉnh của stack
int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s.arr[s.top--];
}

// Duyệt và in ra toàn bộ các phần tử trong stack
void duyetStack(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    s.top = -1;

    push(s, 5);
    push(s, 7);
    push(s, 10);

    duyetStack(s); // In ra: 10 7 5

    pop(s);
    duyetStack(s); // In ra: 7 5

    pop(s);
    pop(s);
    pop(s); // In ra: Stack is empty

    return 0;
}
