#include <iostream>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int partition(int a[], int low, int high, int n) {
    int pivot = a[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    cout << "Trạng thái mảng sau 1 lần partition: ";
    printArray(a, n);
    return i + 1;
}

void quickSort(int a[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(a, low, high, n);
        quickSort(a, low, pi - 1, n);
        quickSort(a, pi + 1, high, n);
    }
}

void merge(int a[], int left, int mid, int right, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[1000], R[1000];  
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    cout << "Trạng thái mảng sau khi trộn: ";
    printArray(a, n);
}

void mergeSort(int a[], int left, int right, int n) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, n);
        mergeSort(a, mid + 1, right, n);
        merge(a, left, mid, right, n);
    }
}

int main() {
    int n;
    cout << "Nhập số phần tử mảng: ";
    cin >> n;

    int arr[1000]; 
    cout << "Nhập các phần tử mảng: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int quickArr[1000], mergeArr[1000];
    for (int i = 0; i < n; i++) {
        quickArr[i] = arr[i];
        mergeArr[i] = arr[i];
    }

    cout << "\nSẮP XẾP NHANH (Quick Sort)\n";
    quickSort(quickArr, 0, n - 1, n);
    cout << "Kết quả cuối cùng: ";
    printArray(quickArr, n);

    cout << "\nSẮP XẾP TRỘN (Merge Sort)\n";
    mergeSort(mergeArr, 0, n - 1, n);
    cout << "Kết quả cuối cùng: ";
    printArray(mergeArr, n);

    cout << "\nPHÂN TÍCH ĐỘ PHỨC TẠP\n";
    cout << "1. Quick Sort:\n";
    cout << "   - Thời gian trung bình: O(n log n)\n";
    cout << "   - Thời gian xấu nhất: O(n^2) (nếu chọn pivot kém)\n";
    cout << "   - Bộ nhớ phụ: O(log n) (do ngăn xếp đệ quy)\n\n";

    cout << "2. Merge Sort:\n";
    cout << "   - Thời gian luôn là: O(n log n)\n";
    cout << "   - Bộ nhớ phụ: O(n) (do dùng mảng tạm)\n";

    return 0;
}
