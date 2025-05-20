#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct NODE {
    int key;
    NODE* p_left;
    NODE* p_right;
};
NODE* createNode(int data)
{
    NODE* newNode = new NODE();
    newNode->key = data;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;
    return newNode;
}
vector<int> NLR(NODE* pRoot)
{
    vector<int> result;
    if (pRoot == nullptr) return result;
    result.push_back(pRoot->key);
    vector<int> leftresult = NLR(pRoot->p_left);
    vector<int> rightresult = NLR(pRoot->p_right);
    result.insert(result.end(), leftresult.begin(), leftresult.end());
    result.insert(result.end(), rightresult.begin(), rightresult.end());
    return result;
}
vector<int> LNR(NODE* pRoot)
{
    vector<int> result;
    if (pRoot == nullptr) return result;
    vector<int> leftresult = LNR(pRoot->p_left);
    result.insert(result.end(), leftresult.begin(), leftresult.end());
    result.push_back(pRoot->key);
    vector<int> rightresult = LNR(pRoot->p_right);
    result.insert(result.end(), rightresult.begin(), rightresult.end());
    return result;
}
vector<int> LRN(NODE* pRoot)
{
    vector<int> result;
    if (pRoot == nullptr) return result;
    vector<int> leftresult = LRN(pRoot->p_left);
    result.insert(result.end(), leftresult.begin(), leftresult.end());
    vector<int> rightresult = LRN(pRoot->p_right);
    result.insert(result.end(), rightresult.begin(), rightresult.end());
    result.push_back(pRoot->key);
    return result;
}
vector<vector<int>> LevelOrder(NODE* pRoot)
{
    vector<vector<int>> result;
    if (pRoot == nullptr) return result;
    queue<NODE*> q;
    q.push(pRoot);
    while (!q.empty())
    {
        int levelsize = q.size();
        vector<int> curlevel;
        for (int i = 0; i < levelsize; i++)
        {
            NODE* node = q.front();
            q.pop();
            curlevel.push_back(node->key);
            if (node->p_left != nullptr) q.push(node->p_left);
            if (node->p_right != nullptr) q.push(node->p_right);
        }
        result.push_back(curlevel);
    }
    return result;
}
int countNode(NODE* pRoot)
{
    if (pRoot == nullptr) return 0;
    return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}
int sumNode(NODE* pRoot)
{
    if (pRoot == nullptr) return 0;
    return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}
int heightNode(NODE* pRoot, int value)
{
    if (pRoot == nullptr) return -1;
    if (pRoot->key == value) return 0;
    int leftheight = heightNode(pRoot->p_left, value);
    int rightheight = heightNode(pRoot->p_right, value);
    if (leftheight != -1) return leftheight + 1;
    if (rightheight != -1) return rightheight + 1;
    return -1;
}
int Level(NODE* pRoot, NODE* p, int level = 0)
{
    if (pRoot == nullptr) return -1;
    if (pRoot == p) return level;
    int leftlevel = Level(pRoot->p_left, p, level + 1);
    if (leftlevel != -1) return leftlevel;
    return Level(pRoot->p_right, p, level + 1);
}
int countLeaf(NODE* pRoot)
{
    if (pRoot == nullptr) return 0;
    if (pRoot->p_left == nullptr && pRoot->p_right == nullptr) return 1;
    return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}
