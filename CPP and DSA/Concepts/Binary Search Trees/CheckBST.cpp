#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include "BinaryTreeNode.h"
using namespace std;

// Mistake: It compares that the root with left and right subchild when we need to compare the leftmax and rightmin
// Just image the case below this function will return this as a BST
//      4
//    /   \
//   2     6
//  / \   / \
// 1  10 5   7
// bool isBST(BinaryTreeNode<int> *root) {
//     bool ans = true;
//     if (root == NULL) return ans;
//     if(root->left != NULL && root->left->data > root->data) {
//         return false;
//     }
//     if(root->right != NULL && root->right->data < root->data) {
//         return false;
//     }
//     ans = isBST(root->left) && isBST(root->right);
//     return ans;
// }

// My solution - Again not good as we miss out a major portion of the work. Comapring the min in the right subtree.
// pair<bool, int> isBST(BinaryTreeNode<int>* root) {
//     // Base case: if the root is NULL, return a valid pair indicating an empty tree.
//     if(root == NULL) {
//         return make_pair(true, -1);
//     }
    
//     // Recursively check the left and right subtrees.
//     pair<bool, int> left = isBST(root->left);
//     pair<bool, int> right = isBST(root->right);
    
//     // If either the left or right subtree is not a BST, return false.
//     if(!left.first || !right.first) {
//         return make_pair(false, -1);
//     }
    
//     // Check if the current root's value is greater than the maximum value in the left subtree
//     // and less than the minimum value in the right subtree.
//     if((left.second == -1 || left.second < root->data) &&
//        (right.second == -1 || right.second > root->data)) {
//         // Return true and the maximum value in the right subtree (since the current node is the root of the subtree).
//         return make_pair(true, (right.second == -1) ? root->data : right.second);
//     }
    
//     // If the above conditions are not met, return false.
//     return make_pair(false, -1);
// }

class isBSTReturn {
    public:
    bool isBST;
    int min;
    int max;
};

isBSTReturn isBST(BinaryTreeNode<int> *root) {
    // Base Case
    if(root == NULL) {
        isBSTReturn base;
        base.isBST = true;
        base.min = INT_MAX;
        base.max = INT_MIN;
        return base;
    }

    isBSTReturn left = isBST(root->left);
    isBSTReturn right = isBST(root->right);

    // Checking everything
    int minFinal = min(left.min, min(root->data, right.min));
    int maxFinal = max(left.max, max(root->data, right.max));
    bool isBSTFinal = (root->data > left.max) && (root->data <= right.min) && left.isBST && right.isBST;

    isBSTReturn ans;
    ans.min = minFinal;
    ans.max = maxFinal;
    ans.isBST = isBSTFinal;
    
    return ans;
}

bool isBSTminmax(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL) return true;

    // if the root->data is out of range
    if(root->data < min || root->data > max) return false;

    // if it is in range
    bool isLeftOk = isBSTminmax(root->left, min, root->data - 1);
    bool isRightOk = isBSTminmax(root->right, root->data, max);

    return isLeftOk && isRightOk;
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
    isBSTReturn bst = isBST(root);
    cout << bst.isBST << endl;
    cout << isBSTminmax(root) << endl;
    delete root;
    return 0;
}