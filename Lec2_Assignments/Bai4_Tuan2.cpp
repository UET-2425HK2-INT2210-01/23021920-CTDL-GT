#include <iostream>
#include <string.h>
using namespace std;
class Queue {
private:
	struct Node {
		int data;
		Node* next;
		Node(int d) {
			data = d;
			next = nullptr;
		}
	};
	Node* front;
	Node* rear;
public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}
	void enqueue(int x) {
		Node* newNode = new Node(x);
		if(rear == nullptr) {
			front = rear = newNode;
		} else {
			rear->next = newNode;
			rear = newNode;
		}
	}
	void dequeue(){
	    if(front == nullptr) return;
	    Node* temp = front;
	    front = front->next;
	    if(front == nullptr) rear = nullptr;
	    delete temp;
	}
	void printQueue(){
	    Node* temp = front;
	    while (temp != nullptr){
	        cout << temp->data << " ";
	        temp = temp->next;
	    }
	    cout << endl;
	}
};
int main()
{
	int n;
	cin >> n;
	Queue q;
	for(int i = 0; i< n; i ++) {
		string command;
		cin >> command;
		if(command == "enqueue") {
		    int x;
		    cin >> x;
		    q.enqueue(x);
		} else if(command == "dequeue"){
		    q.dequeue();
		}
	}
	q.printQueue();
	return 0;
}