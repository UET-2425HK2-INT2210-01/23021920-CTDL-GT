#include <iostream>       
using namespace std;      

// Hàm đệ quy sinh các xâu nhị phân
void generate(int n, string s) {
    if (s.length() == n) {    // Nếu độ dài xâu s đã bằng n
        cout << s << endl;    // In ra xâu nhị phân đầy đủ
        return;               // Kết thúc nhánh đệ quy này
    }
    generate(n, s + "0");     // Gọi đệ quy: thêm '0' vào cuối xâu s
    generate(n, s + "1");     // Gọi đệ quy: thêm '1' vào cuối xâu s
}

int main() {
    int n;                    // Biến n lưu độ dài của số nhị phân
    cin >> n;                 // Nhập số nguyên n từ bàn phím

    generate(n, "");          // Gọi hàm đệ quy bắt đầu với chuỗi rỗng

    return 0;                 
}