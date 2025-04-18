#include <iostream> 
using namespace std;

// Hàm đệ quy tính tổng các chữ số
int sumOfDigits(int n) {
    if (n == 0) // Trường hợp cơ bản: không còn chữ số nào
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10); // Lấy chữ số cuối và cộng đệ quy phần còn lại
}

int main() {
    int n;

    // Nhập số nguyên dương từ bàn phím
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // Kiểm tra đầu vào
    if (n < 0) {
        cout << "Vui long nhap mot so nguyen duong!" << endl;
        return 1;
    }

    // Gọi hàm và in kết quả
    cout << "Tong cac chu so cua n la: " << sumOfDigits(n) << endl;

    return 0;
}
