#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* initTree() {
    return NULL;
}

bool isEmpty(Node* root) {
    return root == NULL;
}

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void addLeft(Node* parent, int x) {
    if (parent == NULL) return;
    if (parent->left == NULL) {
        parent->left = createNode(x);
    }
}

void addRight(Node* parent, int x) {
    if (parent == NULL) return;
    if (parent->right == NULL) {
        parent->right = createNode(x);
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}