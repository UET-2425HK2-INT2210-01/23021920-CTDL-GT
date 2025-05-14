#include <iostream>     // Dùng để nhập xuất dữ liệu
#include <vector>       // Dùng để khai báo mảng 2 chiều (ma trận)
using namespace std;

const int INF = 1e9;    // Một giá trị lớn dùng để biểu diễn "vô cực" (không có đường đi)

// Hàm chính
int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;  // Đọc số đỉnh, số cạnh, điểm bắt đầu s và điểm kết thúc e

    // Khởi tạo ma trận khoảng cách với INF (vô cực)
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Khởi tạo ma trận next để truy vết đường đi
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    // Nhập dữ liệu các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;     // Cạnh từ u đến v có độ bẩn d
        dist[u][v] = d;         // Gán độ bẩn vào ma trận khoảng cách
        next[u][v] = v;         // Ghi nhớ đường đi trực tiếp từ u đến v
    }

    // Gán khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;         // Đường đi từ i đến i là chính nó
    }

    // Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
    for (int k = 1; k <= n; ++k) {           // Đỉnh trung gian
        for (int i = 1; i <= n; ++i) {       // Đỉnh bắt đầu
            for (int j = 1; j <= n; ++j) {   // Đỉnh kết thúc
                // Nếu tồn tại đường đi từ i → k và k → j
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    // Nếu đường i → j qua k ngắn hơn đường hiện tại
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];   // Cập nhật khoảng cách
                        next[i][j] = next[i][k];                // Cập nhật truy vết: đi từ i sang j sẽ đi qua next[i][k]
                    }
                }
            }
        }
    }

    // In ra tổng độ bẩn đường đi từ s đến e
    if (dist[s][e] == INF) {
        cout << "INF\n";    // Không có đường đi
    } else {
        cout << dist[s][e] << "\n";   // In ra tổng độ bẩn nhỏ nhất
    }

    // In đường đi từ s đến e (truy vết từ mảng next)
    if (next[s][e] == -1) {
        cout << "No path\n";   // Không có đường đi
    } else {
        int u = s;
        cout << u << " ";      // In điểm bắt đầu
        while (u != e) {
            u = next[u][e];    // Lấy đỉnh tiếp theo trên đường đi từ u đến e
            cout << u << " ";  // In đỉnh đó
        }
        cout << "\n";
    }

    // In ra ma trận khoảng cách ngắn nhất giữa tất cả các cặp đỉnh
    for (int i = 1; i <= n; ++i) {         // Duyệt từng hàng
        for (int j = 1; j <= n; ++j) {     // Duyệt từng cột
            if (dist[i][j] == INF)
                cout << "INF ";           // Nếu không có đường thì in INF
            else
                cout << dist[i][j] << " "; // In ra độ bẩn nhỏ nhất giữa i và j
        }
        cout << "\n";                     // Xuống dòng sau mỗi hàng
    }

    return 0;   // Kết thúc chương trình
}
