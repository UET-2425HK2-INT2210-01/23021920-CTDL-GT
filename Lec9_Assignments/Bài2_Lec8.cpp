//Sử dụng đệ quy & quay lui
#include <iostream>
using namespace std;

// Hàm đệ quy kiểm tra xem có tồn tại tập con nào có tổng bằng X không
bool checkSubsetSum(int arr[], int n, int X, int index, int currentSum) {
    // Nếu tổng hiện tại bằng X => đã tìm thấy tập con hợp lệ
    if (currentSum == X) return true;

    // Nếu duyệt hết mảng hoặc tổng vượt quá X => không hợp lệ
    if (index == n || currentSum > X) return false;

    // Gọi đệ quy với trường hợp CHỌN phần tử tại vị trí index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum + arr[index]))
        return true;

    // Gọi đệ quy với trường hợp KHÔNG CHỌN phần tử tại vị trí index
    if (checkSubsetSum(arr, n, X, index + 1, currentSum))
        return true;

    // Nếu cả hai nhánh đều không thỏa mãn => trả về false
    return false;
}

int main() {
    int n, X;
    cin >> n >> X;  // Nhập số phần tử và tổng cần tìm

    int arr[100];   // Khai báo mảng với kích thước tối đa 100 phần tử
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Nhập từng phần tử
    }

    // Gọi hàm kiểm tra từ vị trí đầu tiên (index = 0), tổng ban đầu = 0
    if (checkSubsetSum(arr, n, X, 0, 0))
        cout << "YES" << endl;  // Nếu tồn tại tập con phù hợp
    else
        cout << "NO" << endl;   // Nếu không có tập con nào thỏa mãn

    return 0;
}
