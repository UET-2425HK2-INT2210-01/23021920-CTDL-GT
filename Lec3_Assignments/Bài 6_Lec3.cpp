/*Viết cấu trúc stack theo linked list 
/*Viết cấu trúc queue theo linked list 
1.Định nghĩa nút : struct Node
    struct node:
    data: integer;
    next: pointer đến node;
    hàm node(int d):
    data = d;
    next = NULL
2. Định nghĩa Queue: Class Stack
private:
    top : pointer to Node
public:
- Gọi hàm Stack():
    top <- NULL
- Khai báo hàm push(int x):
    newNode<- new Node(x)
        newNode.next <- top
        top<- newNode
- Khai báo hàm pop():
    if top = NULL then:
        return
    temp<- top
    top<- top.next
    delete temp
- Khai báo hàm  printStack():
    temp<- top
    if temp - NULL then
        print new_line
        return
    while temp != NULL do:
        print temp.data
        temp<-temp.next
    print new_line
3. Hàm main:
    int n 
    input n
    gọi Stack s
    for i<-1 to n do:
        input command 
        if command = "push" then
        int s.push(x)
        else if command = "pop" then:
        s.pop()
        
    s.printStack()*/

#include <iostream>
#include <string.h>

using namespace std;
struct Node {
	int data;
	Node* next;
	Node (int d) {
		data = d;
		next = nullptr;
	}
};
class Stack {
private:
	Node* top;
public:
	Stack() {
		top = nullptr;
	}
	void push(int x) {
		Node* newNode = new Node(x);
		newNode->next = top;
		top = newNode;
	}
	void pop() {
		if(top) {
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}
	void printStack() {
		Node* current = top;
		if(!current) {
			cout << endl;
			return;
		}
		while (current) {
			cout << current->data <<" ";
			current = current->next;
		}
		cout << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	Stack s;
	for(int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if(command == "push") {
			int x;
			cin >> x;
			s.push(x);
		} else if(command == "pop") {
			s.pop();
		}
	}
	s.printStack();
	return 0;
}