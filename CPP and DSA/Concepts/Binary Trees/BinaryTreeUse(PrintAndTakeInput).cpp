#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root) {
    if(root == NULL) return;
    cout << root->data << ": ";
    if(root->left != NULL) {
        cout << "L" << root->left->data;
    }
    if(root->right != NULL) {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
    int data;
    cout << "Enter Data: " << endl;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printTree(root);
    delete root;
    return 0;
}