#include <iostream>              
#include <vector>                
#include <queue>                 
using namespace std;

int main() {
    int n, m, X, Y;              // n: số đỉnh, m: số cạnh, X: đỉnh bắt đầu, Y: đỉnh kết thúc
    cin >> n >> m >> X >> Y;     // Nhập n, m, X, Y từ dòng đầu

    vector<vector<int>> adj(n + 1);   // Khai báo danh sách kề, chỉ số từ 1 đến n

    // Nhập m cạnh: mỗi cạnh từ u đến v
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;                // Nhập cạnh u → v
        adj[u].push_back(v);          // Thêm v vào danh sách kề của u
    }

    vector<int> dist(n + 1, -1);      // Mảng lưu khoảng cách từ X đến các đỉnh, khởi tạo -1 (chưa thăm)
    queue<int> q;                     // Hàng đợi dùng cho thuật toán BFS

    dist[X] = 0;                      // Khoảng cách từ X đến chính nó là 0
    q.push(X);                        // Đưa đỉnh bắt đầu vào hàng đợi

    // Bắt đầu duyệt đồ thị theo BFS
    while (!q.empty()) {
        int u = q.front();            // Lấy đỉnh đầu tiên trong hàng đợi
        q.pop();                      // Loại bỏ khỏi hàng đợi

        // Duyệt các đỉnh kề với u
        for (int v : adj[u]) {
            if (dist[v] == -1) {      // Nếu đỉnh v chưa được thăm
                dist[v] = dist[u] + 1; // Cập nhật số cạnh từ X đến v
                q.push(v);            // Đưa v vào hàng đợi để duyệt tiếp
            }
        }
    }

    cout << dist[Y] << endl;          // In ra khoảng cách ngắn nhất từ X đến Y (số cạnh)
    return 0;
}
