#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

// Function to Construct Tree from PreOrder and InOrder
BinaryTreeNode<int> *TreeBuilder(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    // Base Case
    if (preEnd <= preStart)
        return NULL;
    // Make the root node
    int rootData = preorder[preStart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int rootIndex;
    for (int i = inStart; i < inEnd; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // Calculate the start and end of the preorder and inorder for left and right subtree
    int pe = preStart + 1 + rootIndex - inStart;

    // Call the function to build left and right subtree
    BinaryTreeNode<int> *left = TreeBuilder(preorder, inorder, preStart + 1, pe, inStart, rootIndex);
    BinaryTreeNode<int> *right = TreeBuilder(preorder, inorder, pe, preEnd, rootIndex + 1, inEnd);

    // Connect the left and right subtree with root
    root->left = left;
    root->right = right;
    return root;
}


void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    // if the tree is empty return
    if (root == NULL)
        return;
    // Queue for nodes to process
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    // While there are nodes to process in the queue -
    // (process the nodes mean printing the node data and all of it's child's data and storing the children in the queue to be processed)
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int data;
    cout << "Enter the root of the tree: " << endl;
    cin >> data;
    if (data == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> toProcess;
    toProcess.push(root);
    while (!toProcess.empty())
    {
        BinaryTreeNode<int> *front = toProcess.front();
        toProcess.pop();
        int left, right;
        cout << "Enter left child of " << front->data << endl;
        cin >> left;
        cout << "Enter right child of " << front->data << endl;
        cin >> right;
        if (left != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left);
            front->left = leftChild;
            toProcess.push(leftChild);
        }
        if (right != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right);
            front->right = rightChild;
            toProcess.push(rightChild);
        }
    }
    return root;
}

// 1 2 3 4 5 6 -1 -1 -1 -1 -1 7 8 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    delete root;
    return 0;
}