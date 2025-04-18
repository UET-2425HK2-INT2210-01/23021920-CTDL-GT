#include <iostream>      

using namespace std;      

// Hàm đệ quy để tìm ước số chung lớn nhất của hai số nguyên
int gcd(int x, int y) {
    if (y == 0)           // Trường hợp cơ bản: nếu y bằng 0 thì x là GCD
        return x;         // Trả về x (kết quả cuối cùng)
    return gcd(y, x % y); // Gọi đệ quy với cặp mới (y, x chia lấy dư cho y)
}

int main() {
    int x, y;             // Khai báo hai biến nguyên để lưu số được nhập từ bàn phím

    cin >> x >> y;        // Nhập hai số nguyên từ bàn phím (giả lập "Keyboard" trong đề bài)

    cout << gcd(x, y);    // Gọi hàm gcd và in kết quả ra màn hình

    return 0;             
}