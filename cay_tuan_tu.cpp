#include <iostream>
using namespace std;

#define MAX 100

struct ArrayTree {
    int data[MAX];
    bool used[MAX]; // đánh dấu nút tồn tại
};
void initTree(ArrayTree &T) {
    for (int i = 0; i < MAX; i++) {
        T.used[i] = false;
    }
}
bool isEmpty(ArrayTree T) {
    return !T.used[1]; // gốc ở vị trí 1
}
void addRoot(ArrayTree &T, int x) {
    T.data[1] = x;
    T.used[1] = true;
}
void addLeft(ArrayTree &T, int parent, int x) {
    int left = 2 * parent;
    if (T.used[parent] && left < MAX) {
        T.data[left] = x;
        T.used[left] = true;
    }
}

void addRight(ArrayTree &T, int parent, int x) {
    int right = 2 * parent + 1;
    if (T.used[parent] && right < MAX) {
        T.data[right] = x;
        T.used[right] = true;
    }
}
void preorder(ArrayTree T, int i) {
    if (i >= MAX || !T.used[i]) return;
    cout << T.data[i] << " ";
    preorder(T, 2 * i);
    preorder(T, 2 * i + 1);
}
void inorder(ArrayTree T, int i) {
    if (i >= MAX || !T.used[i]) return;
    inorder(T, 2 * i);
    cout << T.data[i] << " ";
    inorder(T, 2 * i + 1);
}
void postorder(ArrayTree T, int i) {
    if (i >= MAX || !T.used[i]) return;
    postorder(T, 2 * i);
    postorder(T, 2 * i + 1);
    cout << T.data[i] << " ";
}
