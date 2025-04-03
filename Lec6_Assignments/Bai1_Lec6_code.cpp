#include <iostream> // Thư viện để nhập/xuất dữ liệu
using namespace std;

// Lớp định nghĩa một nút trong cây tìm kiếm nhị phân (BST)
class TreeNode {
public:
    int val; // Giá trị của nút
    TreeNode* left; // Con trái
    TreeNode* right; // Con phải
    TreeNode(int key) : val(key), left(NULL), right(NULL) {} // Hàm khởi tạo
};

// Hàm chèn một giá trị vào BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key); // Nếu cây rỗng, tạo nút mới
    if (key < root->val)
        root->left = insert(root->left, key); // Chèn vào cây con bên trái nếu nhỏ hơn
    else
        root->right = insert(root->right, key); // Chèn vào cây con bên phải nếu lớn hơn
    return root;
}

// Hàm tìm giá trị nhỏ nhất trong cây con bên phải (dùng khi xóa nút)
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left)
        current = current->left; // Duyệt về phía trái nhất để tìm giá trị nhỏ nhất
    return current;
}

// Hàm xóa một nút khỏi BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root; // Nếu cây rỗng, trả về NULL
    if (key < root->val)
        root->left = deleteNode(root->left, key); // Tìm nút cần xóa trong cây con bên trái
    else if (key > root->val)
        root->right = deleteNode(root->right, key); // Tìm nút cần xóa trong cây con bên phải
    else {
        // Trường hợp nút có một con hoặc không có con
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Trường hợp nút có hai con: tìm giá trị nhỏ nhất trong cây con bên phải
        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val; // Thay giá trị nút cần xóa bằng giá trị nhỏ nhất
        root->right = deleteNode(root->right, temp->val); // Xóa nút giá trị nhỏ nhất vừa tìm được
    }
    return root;
}

// Duyệt cây theo thứ tự trung tố (Inorder Traversal)
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left); // Duyệt cây con bên trái
        cout << root->val << " "; // In giá trị của nút
        inorder(root->right); // Duyệt cây con bên phải
    }
}

int main() {
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Danh sách giá trị để xây dựng BST
    TreeNode* root = NULL;
    for (int v : values) root = insert(root, v); // Chèn từng giá trị vào cây BST
    
    cout << "Cây nhị phân ban đầu (Inorder): ";
    inorder(root); // Hiển thị BST ban đầu theo inorder
    cout << endl;
    
    int insertValues[] = {14, 0, 35}; // Danh sách giá trị cần chèn thêm
    for (int v : insertValues) root = insert(root, v);
    
    cout << "Cây nhị phân sau khi inserting 14, 0, 35 (Inorder): ";
    inorder(root); // Hiển thị BST sau khi chèn
    cout << endl;
    
    int deleteValues[] = {6, 13, 35}; // Danh sách giá trị cần xóa
    for (int v : deleteValues) root = deleteNode(root, v);
    
    cout << "Cây nhị phân sau khi deleting 6, 13, 35 (Inorder): ";
    inorder(root); // Hiển thị BST sau khi xóa
    cout << endl;
    
    return 0; // Kết thúc chương trình
}
