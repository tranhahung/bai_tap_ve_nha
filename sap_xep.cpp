#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partitionFunc(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            cout << "Sau khi hoán đổi: ";
            printArray(arr, n);
        }
    }

    swap(arr[i + 1], arr[high]);
    cout << "Đặt pivot " << pivot << " vào đúng vị trí: ";
    printArray(arr, n);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high, n);

        cout << "Trạng thái sau 1 vòng quickSort: ";
        printArray(arr, n);

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void merge(int arr[], int left, int mid, int right, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        cout << "Sau khi gộp: ";
        printArray(arr, n);
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "Trạng thái sau khi merge [" << left << "," << right << "]: ";
    printArray(arr, n);

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right, int n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, n);
        mergeSort(arr, mid + 1, right, n);
        merge(arr, left, mid, right, n);
    }
}

int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Quick Sort" << endl;
    quickSort(arr1, 0, n - 1, n);
    cout << "Kết quả cuối cùng: ";
    printArray(arr1, n);
    cout << "Độ phức tạp trung bình: O(n log n)\n";
    cout << "Độ phức tạp trường hợp xấu nhất: O(n^2)\n";
    cout << "Độ phức tạp bộ nhớ: O(log n)\n\n";

    cout << "Merge Sort" << endl;
    mergeSort(arr2, 0, n - 1, n);
    cout << "Kết quả cuối cùng: ";
    printArray(arr2, n);
    cout << "Độ phức tạp thời gian: O(n log n)\n";
    cout << "Độ phức tạp bộ nhớ: O(n)\n";

    return 0;
}
