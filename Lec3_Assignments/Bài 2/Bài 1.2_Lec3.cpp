#include <iostream>
using namespace std;
/* Bài toán với độ phức tạp thuật toán 0(logn): 2^n = (2^n/2)^2
- Input : n
- Output: 2^n
1. Khai báo hàm result(int n)
   if( n == 0) return 1;
   if(n >0, n chẵn) return result(n / 2) * result(n / 2);
   if( n >0, n lẻ) return 2 * result((n - 1) / 2) * result((n - 1) / 2);
   if (n< 0; n chẵn) return 1 / (result(n / 2) * result(n / 2));
   if( n<0; n lẻ) return 1 / (2 * result((n - 1) / 2) * result((n - 1) / 2));
2. Khai báo hàm main
   khai báo n;
   nhập n;
   in kết quả result(n);
   */
double result(int n) {
    if (n == 0) return 1;

    if (n > 0) {
        if (n % 2 == 0)  
            return result(n / 2) * result(n / 2);
        else  
            return 2 * result((n - 1) / 2) * result((n - 1) / 2);
    } 
    else 
        n=n*(-1);
        if (n % 2 == 0)  
            return 1 / (result(n / 2) * result(n / 2));
        else  
            return 1 / (2 * result((n - 1) / 2) * result((n - 1) / 2));
    }

int main() {
    int n;
    cin >> n;
    cout << result(n) << endl;
    return 0;
}
