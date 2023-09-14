#include <iostream>
using namespace std;

// Khai báo cấu trúc node cho danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Khai báo cấu trúc stack
struct Stack {
    Node* top;
};

// Hàm tạo mới stack rỗng
void createStack(Stack* &s) {
    s = new Stack;
    s->top = NULL;
}

// Hàm kiểm tra stack rỗng
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// Hàm đẩy (push) một phần tử vào đầu stack
void push(Stack* &s, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

// Hàm lấy (pop) phần tử đầu tiên ra khỏi stack
int pop(Stack* &s) {
    if (isEmpty(s)) {
        cout << "Stack rong\n";
        return -1;
    }
    int result = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    delete temp;
    return result;
}

// Hàm duyệt (traversal) stack và hiển thị các phần tử trong stack
void duyetStack(Stack* s) {
    if (isEmpty(s)) {
        cout << "Stack rong\n";
        return;
    }
    cout << "Cac phan tu trong stack la: ";
    Node* temp = s->top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack* s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);

    duyetStack(s);

    int x = pop(s);
    cout << "Phan tu pop ra la: " << x << endl;

    duyetStack(s);

    return 0;
}
