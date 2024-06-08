#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include "BinaryTreeNode.h"
using namespace std;



pair<int, int> DiameterHeight(BinaryTreeNode<int> *root) {
    //Base Case
    if(root == NULL) {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    //Hypothesis
    pair<int,int> leftResult = DiameterHeight(root->left);
    pair<int,int> rightResult = DiameterHeight(root->right);

    int ld = leftResult.first;
    int lh = leftResult.second;
    int rd = rightResult.first;
    int rh = rightResult.second;

    //Small Calculation
    pair<int,int> ans;
    //diameter
    ans.first = max(lh + rh, max(ld, rd));
    //height
    ans.second = 1 + max(lh, rh);
    

    return ans;
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
    pair<int, int> dh = DiameterHeight(root);
    cout << "Diameter: " << dh.first << endl;
    cout << "Height: " << dh.second << endl;
    delete root;
    return 0;
}