#include <iostream> 
using namespace std;

// Hàm đệ quy đếm số chữ số của một số nguyên dương
int countDigits(int n) {
    if (n < 10) // chỉ còn 1 chữ số
        return 1;
    else
        return 1 + countDigits(n / 10); // Mỗi lần chia 10 bỏ đi 1 chữ số
}

int main() {
    int n;

    // Nhập số nguyên dương
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    // Kiểm tra điều kiện đầu vào
    if (n <= 0) {
        cout << "Vui long nhap mot so nguyen duong!" << endl;
        return 1;
    }

    // Gọi hàm và in kết quả
    cout << "So chu so cua n la: " << countDigits(n) << endl;

    return 0;
}
