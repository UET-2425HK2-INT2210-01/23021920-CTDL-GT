/*Viết Stack bằng mảng
Đánh giá độ phức tạp thuật toán
- Best Case (TH tốt nhất):	Các thao tác push() hoặc pop() chạy trong O(1) nếu stack còn chỗ trống hoặc không rỗng.
- Worst Case (TH xấu nhất)	printStack() chạy trong O(n) nếu cần in toàn bộ stack.
- Average Case (TH trung bình)	Các thao tác cơ bản chạy trong O(1), còn printStack() vẫn là O(n) khi cần.
*/
#include <iostream>
using namespace std;

class Stack {
private:
    int top;         
    int capacity;   
    int* arr;     

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; 
    }
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
)
    void push(int x) {
        if (isFull()) {
            cout << " Không thể thêm phần tử.\n";
            return;
        }
        arr[++top] = x;
        cout << x << " được thêm vào stack.\n";
    }
    void pop() {
        if (isEmpty()) {
            cout << " Không thể xóa phần tử.\n";
            return;
        }
        cout << arr[top] << " được xóa khỏi stack.\n";
        top--;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack rỗng!\n";
            return -1;
        }
        return arr[top];
    }
    void printStack() {
        if (isEmpty()) {
            cout << "Stack rỗng.\n";
            return;
        }
        cout << "Stack hiện tại: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();

    s.pop();
    s.printStack();

    cout <<  s.peek() << endl;

    return 0;
}
