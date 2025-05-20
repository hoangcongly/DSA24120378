#include <iostream>
#include <vector>
using namespace std;

struct NODE {
    int key;
    NODE* p_left;
    NODE* p_right;
};
NODE* Search(NODE* pRoot, int x)
{
    if (pRoot == nullptr) return nullptr;
    if (pRoot->key == x) return pRoot;
    if (pRoot->key > x) return Search(pRoot->p_left, x);
    return Search(pRoot->p_right, x);
}
void Insert(NODE*& pRoot, int x)
{
    if (pRoot != nullptr)
    {
        if (pRoot->key == x) return;
        if (pRoot->key > x) return Insert(pRoot->p_left, x);
        else return Insert(pRoot->p_right, x);
    }
    NODE* newNode = new NODE();
    newNode->key = x;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;
    pRoot = newNode;
}
NODE* findmin(NODE* pRoot)
{
    while (pRoot->p_left != nullptr)
    {
        pRoot = pRoot->p_left;
    }
    return pRoot;
}
void Remove(NODE*& pRoot, int x)
{
    if (pRoot == nullptr) return;
    if (pRoot->key < x) Remove(pRoot->p_right, x);
    else if (pRoot->key > x) Remove(pRoot->p_left, x);
    else
    {
        if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
        }
        else if (pRoot->p_left == nullptr)
        {
            NODE* temp = pRoot;
            pRoot = pRoot->p_right;
            delete temp;
        }
        else if (pRoot->p_right == nullptr)
        {
            NODE* temp = pRoot;
            pRoot = pRoot->p_left;
            delete temp;
        }
        else
        {
            NODE* minnode = findmin(pRoot->p_right);
            pRoot->key = minnode->key;
            Remove(pRoot->p_right, minnode->key);
        }
    }
}
NODE* createNode(int data)
{
    NODE* newNode = new NODE();
    newNode->key = data;
    newNode->p_left = newNode->p_right = nullptr;
    return newNode;
}
NODE* createTree(int a[], int n)
{
    NODE* root = nullptr;
    for (int i = 0; i < n; i++)
    {
        Insert(root, a[i]);
    }
    return root;
}
void removeTree(NODE*& pRoot)
{
    if (pRoot == nullptr) return;
    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);
    delete pRoot;
    pRoot = nullptr;
}
int Height(NODE* pRoot)
{
    if (pRoot == nullptr) return -1;
    return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}
int countLess(NODE* pRoot, int x)
{
    if (pRoot == nullptr) return 0;
    if (pRoot->key < x)
    {
        return 1 + countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
    }
    else return countLess(pRoot->p_left, x);
}
int countGreater(NODE* pRoot, int x)
{
    if (pRoot == nullptr) return 0;
    if (pRoot->key > x)
    {
        return 1 + countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
    }
    else return countGreater(pRoot->p_right, x);
}
bool isBSThelp(NODE* node, int minval, int maxval)
{
    if (node == nullptr) return true;
    if (node->key <= minval || node->key >= maxval) return false;
    return isBSThelp(node->p_left, minval, node->key) && isBSThelp(node->p_right, node->key, maxval);
}
bool isBST(NODE* pRoot)
{
    return isBSThelp(pRoot, INT_MIN, INT_MAX);
}
bool isFullBST(NODE* pRoot)
{
    if (pRoot == nullptr) return true;

    if ((pRoot->p_left == nullptr && pRoot->p_right != nullptr) ||
        (pRoot->p_left != nullptr && pRoot->p_right == nullptr))
        return false;

    return isBST(pRoot) && isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
}

