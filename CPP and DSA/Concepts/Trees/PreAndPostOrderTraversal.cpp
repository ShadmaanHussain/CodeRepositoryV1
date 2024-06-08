#include<iostream>
#include<queue>
#include "TreeNode.cpp"
using namespace std;

void PostOrder(TreeNode<int> *root) {
    if(root == NULL) return;
    for(int i = 0; i < root->children.size(); i++) {
        PostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

TreeNode<int>* TakeInput() {
    int root;
    cout << "Enter root of the tree: " << endl;
    cin >> root;
    TreeNode<int>* rootNode = new TreeNode<int>(root);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(rootNode);
    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i = 0; i < numChild; i++) {
            int data;
            cout << "Enter the data for the " << i <<"th Child for the node " << front->data<< endl;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return rootNode;


}

void printTree(TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        for(int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << ", ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

//1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
int main() {
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // printTree(root);
    TreeNode<int> *root = TakeInput();
    printTree(root);
    PostOrder(root);
    return 0;
}