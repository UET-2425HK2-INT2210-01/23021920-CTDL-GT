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