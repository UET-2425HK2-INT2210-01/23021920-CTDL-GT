/*Viết cấu trúc queue theo linked list 
1.Định nghĩa nút : struct Node
    struct node:
    data: integer;
    next: pointer đến node;
    hàm node(int d):
    data = d;
    next = NULL
2. Định nghĩa Queue: Class Queue
private:
    front : pointer to Node
    rear: pointer to Node
public:
- Gọi hàm Queue():
    front <- NULL
    rear <- NULL
- Khai báo hàm enqueue(int x):
    newNode <- new Node(X)
    If rear = NULL then:
        front <- newNode
        rear <- newNode
    else:
        rear.next <- newNode
        rear <- newNode
- Khai báo hàm dequeue():
    if front = NULL then:
        return
    temp <- front
    front <- front.next
    if front = NULL then:
        rear <- NULL
    delete temp
- Khai báo hàm  printQueue():
    temp <- front
    while temp != NULL do:
        print temp.data
        temp <- temp.next
    print new_line
3. Hàm main:
    int n 
    input na
    gọi Queue q
    for i <- 1 to n do:
        input command 
        if command = "enqueue" then
        int q.enqueue(x)
        else if command = "dequeue" then:
        q.dequeue()
        
    q.printQueue()*/
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