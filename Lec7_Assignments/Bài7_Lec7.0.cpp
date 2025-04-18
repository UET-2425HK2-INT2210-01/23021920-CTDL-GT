#include <iostream>
using namespace std;

// Hàm đệ quy để đảo ngược số
int reverseNumber(int n, int revNum) {
    if (n == 0) // Trường hợp cơ bản: không còn chữ số nào
        return revNum;
    else
        return reverseNumber(n / 10, revNum * 10 + n % 10); 
        // Dịch chữ số hiện tại vào bên trái kết quả và đệ quy phần còn lại
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
    int reversed = reverseNumber(n, 0);
    cout << "So dao nguoc la: " << reversed << endl;

    return 0;
}
