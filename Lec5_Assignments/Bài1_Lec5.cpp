#include <iostream>
using namespace std;

// Cấu trúc Node để đại diện cho mỗi nút trong cây
struct Node {
    int data; // Dữ liệu của nút
    Node* left; // Con trái
    Node* right; // Con phải

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Lớp Tree đại diện cho cây
class BinaryTree {
public:
    Node* root; // Gốc cây

    BinaryTree() {
        root = nullptr; // Khởi tạo gốc cây là NULL
    }

    // Thêm nút con cho một nút trong cây
    void addChild(int parent, int child) {
        if (root == nullptr) {
            root = new Node(parent); // Nếu cây chưa có phần tử, tạo ra nút root
        }
        Node* parentNode = findNode(root, parent); // Tìm nút cha
        if (parentNode != nullptr) {
            if (parentNode->left == nullptr) {
                parentNode->left = new Node(child); // Thêm con trái
            } else if (parentNode->right == nullptr) {
                parentNode->right = new Node(child); // Thêm con phải
            } else {
                cout << "Cây không phải là cây nhị phân!" << endl;
            }
        } else {
            cout << "Không tìm thấy nút cha!" << endl;
        }
    }

    // Tìm nút trong cây
    Node* findNode(Node* node, int data) {
        if (node == nullptr) return nullptr;
        if (node->data == data) return node;

        Node* left = findNode(node->left, data); // Tìm trong cây con trái
        if (left != nullptr) return left;

        return findNode(node->right, data); // Tìm trong cây con phải
    }

    // Tính chiều cao của cây
    int calculateHeight(Node* node) {
        if (node == nullptr) return 0; // Nếu node là NULL thì chiều cao = 0
        int leftHeight = calculateHeight(node->left); // Chiều cao cây con trái
        int rightHeight = calculateHeight(node->right); // Chiều cao cây con phải
        return max(leftHeight, rightHeight) + 1; // Chiều cao là chiều cao con lớn nhất + 1
    }

    // Duyệt theo thứ tự trước (Pre-order)
    void printPreOrder(Node* node) {
        if (node == nullptr) return; // Nếu node là NULL, không làm gì
        cout << node->data << " "; // In dữ liệu của node
        printPreOrder(node->left); // Đệ quy duyệt con trái
        printPreOrder(node->right); // Đệ quy duyệt con phải
    }

    // Duyệt theo thứ tự sau (Post-order)
    void printPostOrder(Node* node) {
        if (node == nullptr) return; // Nếu node là NULL, không làm gì
        printPostOrder(node->left); // Đệ quy duyệt con trái
        printPostOrder(node->right); // Đệ quy duyệt con phải
        cout << node->data << " "; // In dữ liệu của node sau khi duyệt hết các con
    }

    // Kiểm tra xem cây có phải là cây nhị phân không
    bool isBinaryTree(Node* node) {
        if (node == nullptr) return true; // Nếu node là NULL, là cây nhị phân
        if (node->left != nullptr && node->right != nullptr) {
            return isBinaryTree(node->left) && isBinaryTree(node->right); // Đệ quy kiểm tra con trái và con phải
        }
        return true; // Nếu mỗi nút có tối đa 2 con, cây là nhị phân
    }

    // In kết quả của cây
    void printTree() {
        cout << "Chiều cao của cây: " << calculateHeight(root) << endl;
        cout << "Thứ tự theo di chuyển trước: ";
        printPreOrder(root); // In theo thứ tự trước
        cout << endl;
        cout << "Thứ tự theo di chuyển sau: ";
        printPostOrder(root); // In theo thứ tự sau
        cout << endl;
        if (isBinaryTree(root)) { // Kiểm tra cây nhị phân
            cout << "Cây là cây nhị phân. Thứ tự các nút: ";
            printPreOrder(root); // In theo thứ tự trước nếu cây là nhị phân
            cout << endl;
        } else {
            cout << "NOT BINARY TREE" << endl; // Nếu không phải cây nhị phân
        }
    }
};

// Hàm main - điểm bắt đầu của chương trình
int main() {
    BinaryTree tree; // Khởi tạo cây
    int N, M;
    cin >> N >> M; // Nhập số lượng nút và cạnh

    // Nhập M cạnh, mỗi cạnh có dạng (u, v), nghĩa là u là cha của v
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // Nhập các cạnh
        tree.addChild(u, v); // Thêm cạnh vào cây
    }

    tree.printTree(); // In kết quả

    return 0;
}
