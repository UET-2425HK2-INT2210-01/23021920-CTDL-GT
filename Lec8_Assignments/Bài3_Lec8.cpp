#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;                 // Nhập số vật và tổng trọng lượng tối đa

    int w[100], v[100];           // mảng trọng lượng và giá trị
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];      // Nhập từng cặp (trọng lượng, giá trị)
    }

    int dp[1001] = {0};           // dp[i] = giá trị tối đa nếu trọng lượng là i

    for (int i = 0; i < n; i++) {
        // Duyệt ngược để tránh ghi đè trạng thái trước
        for (int j = X; j >= w[i]; j--) {
            if (dp[j - w[i]] + v[i] > dp[j]) {
                dp[j] = dp[j - w[i]] + v[i]; // cập nhật giá trị tối đa
            }
        }
    }

    cout << dp[X] << endl;       // In ra giá trị lớn nhất
    return 0;
}
