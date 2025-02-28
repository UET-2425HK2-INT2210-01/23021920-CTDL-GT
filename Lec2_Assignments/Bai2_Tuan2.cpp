#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một Node
struct Node {
    int data;
    Node* next;
    Node(int d_) {
        data = d_;
        next = nullptr;
    }
};

// Định nghĩa lớp danh sách liên kết
class LinkedList {
public:
    Node* head;
    int len;

    LinkedList() {
        head = nullptr;
        len = 0;
    }

    // In danh sách liên kết
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Chèn phần tử vào vị trí p
    void insert(int p, int x) {
        if (p < 0 || p > len) return; // Kiểm tra vị trí hợp lệ
        Node* newNode = new Node(x);
        
        if (p == 0) { // Chèn đầu danh sách
            newNode->next = head;
            head = newNode;
        } else { // Chèn vào vị trí khác
            Node* temp = head;
            for (int i = 0; i < p - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        len++;
    }

    // Xóa phần tử tại vị trí p
    void remove(int p) {
        if (p < 0 || p >= len || head == nullptr) return; // Kiểm tra hợp lệ

        if (p == 0) { // Xóa đầu danh sách
            Node* temp = head;
            head = head->next;
            delete temp;
        } else { // Xóa vị trí khác
            Node* temp = head;
            for (int i = 0; i < p - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        len--;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n; // Số lượng thao tác

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (command == "delete") {
            int p;
            cin >> p;
            list.remove(p);
        }
    }

    list.print(); // In danh sách kết quả
    return 0;
}
