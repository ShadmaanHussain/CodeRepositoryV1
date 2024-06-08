#include<iostream>
#include "TreeNode.cpp"
using namespace std;

TreeNode<int>* TakeInput() {
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int children;
    cout << "Enter number of children of " << rootData << endl;
    cin >> children;
    for(int i = 0; i < children; i++) {
        TreeNode<int> *child = TakeInput();
        root->children.push_back(child);
    }
    return root;

}

void printTree(TreeNode<int> *root) {
    if(root == nullptr) return;
    cout << root->data << ": ";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

int main() {
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // printTree(root);
    TreeNode<int> *root = TakeInput();
    printTree(root);
    return 0;
}