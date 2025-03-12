// Kiểm tra dãy ngoặc hợp lệ với Stack
#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char c) {
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }

    char peek() {
        return isEmpty() ? '\0' : top->data;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

bool isValidParentheses(const string& str) {
    Stack stack;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) return false;
            char topChar = stack.peek();
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string input;
    cout << "Nhap chuoi ngoac: ";
    cin >> input;
    cout << (isValidParentheses(input) ? "Valid\n" : "Invalid\n");
    return 0;
}
