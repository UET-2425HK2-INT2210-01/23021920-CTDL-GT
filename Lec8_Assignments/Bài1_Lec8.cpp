#include <iostream>
using namespace std;

// Hàm hoán đổi 2 giá trị
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp nhanh (quicksort) từ vị trí low đến high
void quickSort(int a[], int low, int high) {
    if (low >= high) return;

    int pivot = a[(low + high) / 2];  // Chọn phần tử giữa làm pivot
    int i = low, j = high;

    while (i <= j) {
        while (a[i] < pivot) i++;     // Tìm phần tử lớn hơn pivot
        while (a[j] > pivot) j--;     // Tìm phần tử nhỏ hơn pivot
        if (i <= j) {
            swap(a[i], a[j]);         // Hoán đổi 2 phần tử
            i++;
            j--;
        }
    }

    // Đệ quy sắp xếp 2 nửa
    quickSort(a, low, j);
    quickSort(a, i, high);
}

int main() {
    int n;
    cin >> n;               // Nhập số phần tử
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];        // Nhập từng phần tử

    quickSort(a, 0, n - 1); // Gọi hàm sắp xếp

    for (int i = 0; i < n; i++)
        cout << a[i] << " "; // In kết quả đã sắp xếp
    return 0;
}
