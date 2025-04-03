// Cây theo MinHeap
#include <iostream>
using namespace std;

// Class định nghĩa MinHeap (Heap nhị phân tối thiểu)
class MinHeap {
private:
    int* heap;       // Mảng chứa các phần tử của heap
    int capacity;    // Dung lượng tối đa của heap
    int size;        // Số lượng phần tử hiện tại

    // Hàm đẩy giá trị lên để duy trì tính chất MinHeap
    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {  // So sánh với nút cha
            swap(heap[index], heap[(index - 1) / 2]);  // Hoán đổi nếu nhỏ hơn cha
            index = (index - 1) / 2;  // Di chuyển lên cha
        }
    }

    // Hàm đẩy giá trị xuống để duy trì tính chất MinHeap
    void heapifyDown(int index) {
        int smallest = index;  
        int left = 2 * index + 1;  // Vị trí con trái
        int right = 2 * index + 2; // Vị trí con phải

        // Tìm nút nhỏ nhất trong cha, con trái và con phải
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        // Nếu nhỏ nhất không phải là cha, đổi chỗ và tiếp tục đẩy xuống
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor: Khởi tạo heap với dung lượng tối đa
    MinHeap(int cap) : capacity(cap), size(0) {
        heap = new int[cap];  // Cấp phát mảng động
    }

    // Hàm chèn một giá trị vào heap
    void insert(int val) {
        if (size == capacity) return;  // Kiểm tra nếu heap đầy
        heap[size] = val;  // Thêm phần tử vào cuối
        heapifyUp(size);  // Đảm bảo tính chất MinHeap
        size++;
    }

    // Hàm xóa một giá trị khỏi heap
    void deleteValue(int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (heap[i] == val) {  // Tìm giá trị cần xóa
                index = i;
                break;
            }
        }
        if (index == -1) return;  // Không tìm thấy giá trị

        heap[index] = heap[size - 1];  // Đưa phần tử cuối cùng lên thay thế
        size--;  // Giảm kích thước heap
        heapifyDown(index);  // Điều chỉnh lại heap
    }

    // Hàm duyệt và in Postorder (LNR - trái, phải, gốc)
    void printPostorder(int index) {
        if (index >= size) return;
        printPostorder(2 * index + 1);  // Duyệt trái
        printPostorder(2 * index + 2);  // Duyệt phải
        cout << heap[index] << " ";  // In gốc
    }

    // Hàm duyệt và in Inorder (LNR - trái, gốc, phải)
    void printInorder(int index) {
        if (index >= size) return;
        printInorder(2 * index + 1);  // Duyệt trái
        cout << heap[index] << " ";   // In gốc
        printInorder(2 * index + 2);  // Duyệt phải
    }

    // Hàm duyệt và in Preorder (NLR - gốc, trái, phải)
    void printPreorder(int index) {
        if (index >= size) return;
        cout << heap[index] << " ";  // In gốc
        printPreorder(2 * index + 1);  // Duyệt trái
        printPreorder(2 * index + 2);  // Duyệt phải
    }

    // Hàm in kết quả duyệt cây theo ba kiểu
    void printTraversalResults() {
        cout << "Postorder: ";
        printPostorder(0);
        cout << endl;

        cout << "Inorder: ";
        printInorder(0);
        cout << endl;

        cout << "Preorder: ";
        printPreorder(0);
        cout << endl;
    }
};

int main() {
    MinHeap heap(15);  // Tạo một heap với dung lượng tối đa là 15
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};  // Dữ liệu ban đầu
    for (int v : values) heap.insert(v);  // Chèn các giá trị vào heap

    // Chèn thêm một số giá trị
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);

    // Xóa một số giá trị
    heap.deleteValue(6);
    heap.deleteValue(13);
    heap.deleteValue(35);

    // In kết quả duyệt cây theo ba kiểu
    heap.printTraversalResults();
    
    return 0;
}
