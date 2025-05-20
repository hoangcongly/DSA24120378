#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct NODE {
    int key;
    NODE* p_left;
    NODE* p_right;
    int height;
};

NODE* createNode(int data)
{
    NODE* newNode = new NODE();
    newNode->key = data;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;
    newNode->height = 0;
    return newNode;
}

int heightTree(NODE* root)
{
    if (root == nullptr) return 0;
    int heightLeft = heightTree(root->p_left) + 1;
    int heightRight = heightTree(root->p_right) + 1;
    return max(heightLeft, heightRight);
}

int getHeight(NODE* PRoot)
{
    if (PRoot == nullptr) return -1;
    return PRoot->height;
}
void updateHeight(NODE* node)
{
    if (node != nullptr)
        node->height = 1 + max(getHeight(node->p_left), getHeight(node->p_right));
}
int dolech(NODE* pRoot)
{
    if (pRoot == nullptr) return 0;
    return getHeight(pRoot->p_left) - getHeight(pRoot->p_right);
}

NODE* rotateLeft(NODE*& a)
{
    NODE* b = a->p_right;
    a->p_right = b->p_left;
    b->p_left = a;
    updateHeight(a);
    updateHeight(b);
    return b;
}
NODE* rotateRight(NODE*& a)
{
    NODE* b = a->p_left;
    a->p_left = b->p_right;
    b->p_right = a;
    updateHeight(a);
    updateHeight(b);
    return b;
}
void Insert(NODE*& pRoot, int x)
{
    if (pRoot == nullptr)
    {
        pRoot = createNode(x);
        return;
    }
    if (pRoot->key > x)
    {
        Insert(pRoot->p_left, x);
    }
    else if (pRoot->key < x)
    {
        Insert(pRoot->p_right, x);
    }
    else return;
    updateHeight(pRoot);
    int lech = dolech(pRoot);
    if (lech > 1)
    {
        if (x < pRoot->p_left->key)
        {
            pRoot = rotateRight(pRoot);
        }
        else
        {
            pRoot->p_left = rotateLeft(pRoot->p_left);
            pRoot = rotateRight(pRoot);
        }
    }
    else if (lech < -1)
    {
        if (x > pRoot->p_right->key)
        {
            pRoot = rotateLeft(pRoot);
        }
        else
        {
            pRoot->p_right = rotateRight(pRoot->p_right);
            pRoot = rotateLeft(pRoot);
        }
    }
}
NODE* findMin(NODE* pRoot)
{
    if (pRoot == nullptr) return nullptr;
    while (pRoot->p_left != nullptr)
    {
        pRoot = pRoot->p_left;
    }
    return pRoot;
}
void Remove(NODE*& pRoot, int x)
{
    if (pRoot == nullptr) return;
    if (pRoot->key < x)
    {
        Remove(pRoot->p_right, x);
    }
    else if (pRoot->key > x)
    {
        Remove(pRoot->p_left, x);
    }
    else
    {
        if (pRoot->p_left == nullptr && pRoot->p_right == nullptr)
        {
            delete pRoot;
            pRoot = nullptr;
        }
        else if (pRoot->p_left == nullptr)
        {
            NODE* temp = pRoot->p_right;
            delete pRoot;
            pRoot = temp;
        }
        else if (pRoot->p_right == nullptr)
        {
            NODE* temp = pRoot->p_left;
            delete pRoot;
            pRoot = temp;
        }
        else
        {
            NODE* temp = findMin(pRoot->p_right);
            pRoot->key = temp->key;
            Remove(pRoot->p_right, temp->key);
        }
    }
    if (pRoot == nullptr) return;
    updateHeight(pRoot);
    int lech = dolech(pRoot);
    if (lech > 1)
    {
        if (dolech(pRoot->p_left) >= 0)
        {
            pRoot = rotateRight(pRoot);
        }
        else
        {
            pRoot->p_left = rotateLeft(pRoot->p_left);
            pRoot = rotateRight(pRoot);
        }
    }
    else if (lech < -1)
    {
        if (dolech(pRoot->p_right) <= 0)
        {
            pRoot = rotateLeft(pRoot);
        }
        else
        {
            pRoot->p_right = rotateRight(pRoot->p_right);
            pRoot = rotateLeft(pRoot);
        }
    }
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
int getHeightCheck(NODE* node)
{
    if (node == nullptr) return -1;
    return 1 + max(getHeightCheck(node->p_left), getHeightCheck(node->p_right));
}
bool isAVLhelp(NODE* node)
{
    if (node == nullptr) return true;
    int leftHeight = getHeightCheck(node->p_left);
    int rightHeight = getHeightCheck(node->p_right);
    int kc = leftHeight - rightHeight;
    if (kc < -1 || kc>1) return false;
    return isAVLhelp(node->p_left) && isAVLhelp(node->p_right);
}
bool isAVL(NODE* pRoot)
{
    return isBST(pRoot) && isAVLhelp(pRoot);
}

