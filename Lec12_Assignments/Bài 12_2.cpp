#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc biểu diễn 1 cạnh của đồ thị
struct Edge {
    int u, v, cost;

    // So sánh hai cạnh theo chi phí để sắp xếp tăng dần
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// Cấu trúc dữ liệu Union-Find (Disjoint Set Union - DSU) để kiểm tra chu trình
class DSU {
    vector<int> parent;

public:
    // Hàm khởi tạo: ban đầu mỗi đỉnh là 1 tập riêng biệt (cha của chính nó)
    DSU(int n) {
        parent.resize(n + 1); // Đánh số từ 1 đến n
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Tìm gốc của tập chứa đỉnh u (với nén đường đi)
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    // Hợp nhất 2 tập chứa đỉnh u và v. Trả về true nếu hợp nhất thành công.
    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v)
            return false; // u và v đã cùng tập => tạo chu trình nếu nối
        parent[root_u] = root_v; // Gộp tập u vào tập v
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Đọc số lượng đỉnh và số cạnh

    vector<Edge> edges; // Danh sách cạnh

    // Nhập m dòng cạnh: u, v là hai máy tính; d là chi phí kết nối
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // Sắp xếp các cạnh theo chi phí tăng dần
    sort(edges.begin(), edges.end());

    DSU dsu(n); // Khởi tạo DSU cho n đỉnh
    vector<Edge> mst; // Danh sách các cạnh thuộc cây khung nhỏ nhất
    int total_cost = 0; // Biến lưu tổng chi phí của cây khung

    // Duyệt từng cạnh sau khi đã sắp xếp
    for (Edge e : edges) {
        // Nếu cạnh không tạo chu trình, thêm vào cây khung
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);         // Ghi nhận cạnh vào cây khung
            total_cost += e.cost;     // Cộng chi phí vào tổng
            if (mst.size() == n - 1)  // Đủ n - 1 cạnh thì cây khung hoàn thành
                break;
        }
    }

    // Xuất kết quả: tổng chi phí trước
    cout << total_cost << endl;

    // Sau đó là danh sách các cạnh được chọn
    for (Edge e : mst) {
        cout << e.u << " " << e.v << " " << e.cost << endl;
    }

    return 0;
}
