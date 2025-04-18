#include <iostream>
using namespace std;


int fibonacci(int n) {
    // Trường hợp cơ bản: nếu n = 0 thì trả về 0
    if (n == 0) return 0;

    // Trường hợp cơ bản: nếu n = 1 thì trả về 1
    if (n == 1) return 1;
    // Trường hợp tổng quát: F(n) = F(n-1) + F(n-2)
    // Gọi đệ quy để tính F(n-1) và F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n; 
    cin >> n;
    // Gọi hàm fibonacci và in ra kết quả
    cout << fibonacci(n) << endl;

    return 0; 
}
