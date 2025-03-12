//Cài danh sách liên kết đơn
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int d_) {
        data = d_;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int len;

    LinkedList() {
        head = nullptr;
    }
    void append(int x) {
        Node *newNode = new Node(x);
        if (head == nullptr) { 
        head = newNode;
        } else { 
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void search (int x){
        Node* temp = head;
        int i=0;
        while (temp){
            if(temp->data == x){
                cout << i <<" ";
                return;
            }
            temp= temp->next;
            i++;
        }
        cout << "NO";
    }
    
    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
    
int main() {
    LinkedList list;
    int n;
    cin >> n; // Số lượng thao tác

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        }
        if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        }
        else if(command == "reverse"){
            list.reverse();
            list.print();
        }
    }

    return 0;
}
