/*Bài toán thực hiện với độ phức tạp O(1)
- Input: n
- Ouput: 2^n
1. Khai báo hàm bitleft(int n)
   khai báo biến result;
   If n>=0 then result=1<< n
   else result= 1/(1<<-(n))
   return result
2. Khai báo main
    khai báo biến n
    Nhập n
    In bitleft(n)*/
   
#include <iostream>
using namespace std;
double bitleft(int n){
    double result;
        if(n>=0){
            result = 1<< n;
        }
        else {
            result = 1<< -(n);
            result = 1/result;
        }
        return result;
}

int main()
{
    int n;
    cin >> n;
    cout << bitleft(n);

    return 0;
}