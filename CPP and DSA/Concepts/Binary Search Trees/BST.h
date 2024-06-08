#include "BinaryTreeNode.h"
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        delete root;
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;

        if (data < node->data)
        {
            return hasData(data, node->left);
        }
        return hasData(data, root->right);
    }

    void Insert(BinaryTreeNode<int> *root, BinaryTreeNode<int> *prev, int data) {
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        //Base Case
        if(root == nullptr && prev == nullptr) {
            root = newNode;
        }
        if(root == nullptr) {
            if(data > prev->data) {
                prev->right = newNode;
            } else {
                prev->left = newNode;
            }
        }
        if(data > root->data) {
            Insert(root->right, root, data);
        } else {
            Insert(root->left, root, data);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void Insert(int data) {

    }

    void Delete(int data) {

    }
};