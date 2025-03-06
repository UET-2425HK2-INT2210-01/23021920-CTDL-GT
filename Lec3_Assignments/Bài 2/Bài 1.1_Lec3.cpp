#include <iostream>
using namespace std;
/*Tính 2^n với độ phức tạp thuật toán 0(n)
- Input : n
- Output: 2^n
 1. Khai báo Hàm result(int n):
 2. Khai báo a = 1 
     Nếu (n<0):
         sử dụng vòng for lặp i từ 0 đến n-1;
         a= a*2
         return 1/a
    Nếu n>0:
    sử dụng vòng for lặp i từ 0 đến n-1
    a= a*2;
    return a
  3.Khai báo hàm main
    Khai báo số nguyên n
    Nhập n
    In ra kết quả hàm result*/
double result(int n){
    double a= 1;
    if(n<0){
        n = n*(-1);
        for (int i=0 ; i< n;i++){
            a*=2;
        }
        return 1/a;
    }
    else{
    for (int i=0;i<n;i++){
        a=a*2;
    }
    return a;
    }
}
int main(){
    int n;
    cin >> n;
    cout << result(n) << endl;
    return 0;
}