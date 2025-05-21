#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1005; // Số lượng đỉnh (công việc) tối đa

// Khai báo danh sách kề, mỗi đỉnh có thể nối với nhiều đỉnh khác
vector<int> adj[MAX];

// Mảng lưu bậc vào (số lượng công việc phải hoàn thành trước 1 công việc)
int indegree[MAX] = {0};

// ==============================
// Hàm thực hiện thuật toán Kahn (BFS Topological Sort)
// Tham số:
//   - n: số công việc (số đỉnh)
// Trả về:
//   - vector<int>: chứa thứ tự thực hiện các công việc theo topo
// ==============================
vector<int> topologicalSort_Kahn(int n) {
    queue<int> q;          // Hàng đợi lưu các đỉnh có bậc vào = 0
    vector<int> order;     // Lưu kết quả thứ tự topo

    // Bước 1: Tìm các đỉnh có bậc vào = 0 (không phụ thuộc công việc nào)
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);     // Đưa vào hàng đợi để xử lý
        }
    }

    // Bước 2: Xử lý hàng đợi
    while (!q.empty()) {
        int u = q.front(); // Lấy công việc đầu hàng đợi
        q.pop();

        order.push_back(u); // Thêm công việc này vào kết quả

        // Duyệt qua các công việc phụ thuộc vào u (cạnh u → v)
        for (int v : adj[u]) {
            indegree[v]--;        // Vì u đã hoàn thành, giảm bậc vào của v
            if (indegree[v] == 0) {
                q.push(v);        // Nếu v không còn phụ thuộc → thêm vào hàng đợi
            }
        }
    }

    // Bước 3: Kiểm tra đồ thị có chu trình không
    if ((int)order.size() != n) {
        // Nếu không sắp xếp đủ n đỉnh → có chu trình → trả về rỗng
        return {};
    }

    return order; // Trả về thứ tự topo
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số lượng công việc (đỉnh) và số quan hệ phụ thuộc (cạnh)

    // Nhập m cặp quan hệ (u, v): nghĩa là công việc u phải làm trước công việc v
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // Thêm cạnh từ u → v vào danh sách kề
        indegree[v]++;       // Tăng bậc vào của v (v có thêm 1 công việc phụ thuộc)
    }

    // Gọi hàm Kahn để sắp xếp topo
    vector<int> result = topologicalSort_Kahn(n);

    // In kết quả
    if (result.empty()) {
        cout << "There is a cycle in the job dependencies." << endl;
    } else {
        for (int job : result) {
            cout << job << " ";
        }
        cout << endl;
    }

    return 0;
}
