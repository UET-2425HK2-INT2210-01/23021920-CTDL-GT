/*Viết cấu trúc queue theo mảng
Độ phức tạp thuật toán:
Average case: O(n) (với enqueue và dequeue bình thường).
Worst case: O(n²) (nếu gọi printQueue sau mỗi thao tác).
*/
#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr; 
public:
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = null;
        rear = null;
    }
    bool isFull() {
        return rear == size - 1;
    }
    bool isEmpty() {
        return front > rear;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        front++;
    }
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue() {
        delete[] arr;
    }
};
int main() {
    int n;
    cin >> n;
    Queue q(100);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (command == "dequeue") {
            q.dequeue();
        }
    }

    q.printQueue(); 

    return 0;
}
