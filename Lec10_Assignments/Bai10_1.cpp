#include <iostream>            
#include <vector>              
using namespace std;

vector<vector<int>> adj;       // Danh sách kề (adjacency list) cho đồ thị
vector<bool> visited;          // Mảng đánh dấu các đỉnh đã được thăm

// Hàm DFS (Duyệt đồ thị theo chiều sâu) từ đỉnh u
void dfs(int u) {
    visited[u] = true;         // Đánh dấu đỉnh u đã được thăm
    for (int v : adj[u]) {     // Duyệt các đỉnh kề với u
        if (!visited[v])       // Nếu đỉnh v chưa được thăm
            dfs(v);            // Gọi đệ quy tiếp tục duyệt từ v
    }
}

int main() {
    int n, m;                  // n: số đỉnh, m: số cạnh
    cin >> n >> m;             // Nhập số đỉnh và số cạnh

    adj.resize(n + 1);         // Khởi tạo danh sách kề (1-indexed)
    visited.resize(n + 1, false); // Khởi tạo mảng visited ban đầu là false

    // Nhập m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;         // Nhập cạnh giữa u và v
        adj[u].push_back(v);   // Thêm v vào danh sách kề của u
        adj[v].push_back(u);   // Thêm u vào danh sách kề của v (vì đồ thị vô hướng)
    }

    int components = 0;        // Biến đếm số thành phần liên thông

    // Duyệt tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {     // Nếu đỉnh i chưa được thăm
            ++components;      // Tăng số lượng thành phần liên thông
            dfs(i);            // Duyệt toàn bộ thành phần liên thông bắt đầu từ i
        }
    }

    cout << components << endl; // In ra số thành phần liên thông
    return 0;
}
