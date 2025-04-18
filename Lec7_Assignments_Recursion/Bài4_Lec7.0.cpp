#include <iostream> 
using namespace std;

// Hàm đệ quy tính x^n
int power(int x, int n) {
    if (n == 0)           // x^0 = 1
        return 1;
    else
        return x * power(x, n - 1); // Gọi đệ quy: x^n = x * x^(n-1)
}

int main() {
    int x, n;

    // Nhập x và n từ bàn phím
    cout << "Nhap x: ";
    cin >> x;

    cout << "Nhap n: ";
    cin >> n;
    cout << "Ket qua x^n la: " << power(x, n) << endl;

    return 0;
}
