#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    char mssv[20];
    int year;
    float gpa;
};

struct Node {
    Student data;
    Node* next;
};

Node* createList() {
    return NULL;
}

Node* createNode(Student sv) {
    Node* p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}

void addLast(Node*& head, Student sv) {
    Node* p = createNode(sv);
    if (head == NULL) {
        head = p;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;
}

void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << "Ho ten: " << p->data.name << ", MSSV: " << p->data.mssv
             << ", Nam sinh: " << p->data.year << ", GPA: " << p->data.gpa << endl;
        p = p->next;
    }
}

int length(Node* head) {
    int cnt = 0;
    Node* p = head;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int countHighGPA(Node* head) {
    int cnt = 0;
    Node* p = head;
    while (p != NULL) {
        if (p->data.gpa > 3.2)
            cnt++;
        p = p->next;
    }
    return cnt;
}

void sortList(Node*& head) {
    if (!head) return;
    bool swapped;

    do {
        swapped = false;
        Node* p = head;
        while (p->next != NULL) {
            if (p->data.gpa > p->next->data.gpa) {
                Student temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

void insertSorted(Node*& head, Student sv) {
    Node* p = createNode(sv);

    if (head == NULL || sv.gpa < head->data.gpa) {
        p->next = head;
        head = p;
        return;
    }

    Node* cur = head;
    while (cur->next != NULL && cur->next->data.gpa < sv.gpa) {
        cur = cur->next;
    }

    p->next = cur->next;
    cur->next = p;
}

int main() {
    Node* list = createList();

    Student s1 = {"Nguyen Van A", "2022001", 2002, 3.5};
    Student s2 = {"Tran Thi B", "2022002", 2003, 2.8};
    Student s3 = {"Le Van C", "2022003", 2002, 3.9};

    addLast(list, s1);
    addLast(list, s2);
    addLast(list, s3);

    cout << "Danh sach sinh vien ban dau:\n";
    printList(list);

    cout << "\nDo dai danh sach: " << length(list) << endl;
    cout << "So sinh vien GPA > 3.2: " << countHighGPA(list) << endl;

    cout << "\nDanh sach sau khi sap xep theo GPA tang dan:\n";
    sortList(list);
    printList(list);

    // Thêm sinh viên GPA = 2.4 vào đúng vị trí
    Student newSV = {"Sinh Vien Moi", "2022999", 2004, 2.4};
    insertSorted(list, newSV);

    cout << "\nDanh sach sau khi them sinh vien GPA = 2.4:\n";
    printList(list);

    return 0;
}
