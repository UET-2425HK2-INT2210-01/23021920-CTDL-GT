#include <iostream>  

using namespace std;

// Hàm sắp xếp mảng các số thực theo thứ tự tăng dần
void sort(float a[], int n) {
    // Duyệt qua từng cặp phần tử trong mảng
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            // Nếu phần tử đứng trước lớn hơn phần tử sau => hoán đổi vị trí
            if (a[i] > a[j]) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main() {
    float a[1000];  // Mảng lưu các số thực (giả định không vượt quá 1000 số)
    int n = 0;      // Biến đếm số lượng phần tử đọc được

    // Nhập dữ liệu từ bàn phím thay cho đọc file
    // Nhập kết thúc khi gặp ký hiệu kết thúc file (EOF - thường là Ctrl+D trên Linux/macOS hoặc Ctrl+Z trên Windows)
    while (cin >> a[n]) {
        n++;  // Tăng biến đếm sau mỗi lần đọc được một số
    }

    // Gọi hàm sắp xếp mảng theo thứ tự tăng dần
    sort(a, n);

    // In kết quả ra màn hình, cách nhau bởi dấu cách
    for (int i = 0; i < n; ++i) {
        cout << a[i];             // In ra phần tử thứ i
        if (i < n - 1) cout << " "; // Thêm dấu cách giữa các số (trừ số cuối)
    }

    return 0; 
}