#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
	node (int d_) {
		data = d_;
		next = nullptr;
		prev = nullptr;
	}
};
class doublylinkedlist {
public:
	node* head;
	node* tail;
	int len;

	doublylinkedlist() {
		head = nullptr;
		tail = nullptr;
		len = 0;
	}
	void print() {
		node * temp = head;
		while (temp) {
			cout << temp->data <<" ";
			temp = temp->next;
		}
		cout << endl;
	}
	void append (int data) {
		node* newNode = new node(data);
		if(!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		len++;
	}
	int  count_triplets() {
		if(len<3) return 0;
		int count = 0;
		node* curr = head->next;
		while (curr && curr->next) {
			if(curr->prev->data + curr->data + curr->next->data == 0)
				count ++;
			curr = curr -> next;
		}
		return count;
	}
};
int main()
{	int n;
	cin >> n;
	doublylinkedlist list;
	for (int i = 0; i<n; i++) {
		int value;
		cin >> value;
		list.append(value);
	}
	cout << list.count_triplets()<< endl;
	return 0;

	return 0;
}