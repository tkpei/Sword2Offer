#include <queue>
#include <stack>
#include <string>

#include "gtest/gtest.h"

#include "binary_tree.h"

BinaryTree::BinaryTree(std::initializer_list<int> list) : pRoot_(NULL)
{
    if (list.size() <= 0 && *list.begin() != nonode)
        return;

    std::queue<TreeNode** > treeNodeQueue;
    auto it = list.begin();

    treeNodeQueue.push(&pRoot_);

    while (it != list.end())
    {
        TreeNode** temp = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (*it != nonode)
        {
            (*temp) = new TreeNode(*it);
            treeNodeQueue.push(&((*temp)->left));
            treeNodeQueue.push(&((*temp)->right));
        }
        else
        {
            treeNodeQueue.push(NULL);
            treeNodeQueue.push(NULL);
        }
        it++;
    }
    return;
}

BinaryTree::~BinaryTree()
{
    if (pRoot_ == NULL)
        return;

    std::queue<TreeNode*> treeNodeQueue;
    treeNodeQueue.push(pRoot_);
    while (treeNodeQueue.size() > 0)
    {
        TreeNode * temp = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (temp != NULL)
        {
            treeNodeQueue.push((temp->left));
            treeNodeQueue.push(temp->right);
            delete temp;
        }
    }
}

bool BinaryTree::operator==(const BinaryTree& tree) const
{
    TreeNode* pRootOther = tree.getRoot();
    std::queue<TreeNode*> treeNodeQueue0;
    std::queue<TreeNode*> treeNodeQueue1;

    treeNodeQueue0.push(pRoot_);
    treeNodeQueue1.push(pRootOther);

    while (treeNodeQueue0.size() > 0)
    {
        TreeNode* node, *nodeOther;
        node = treeNodeQueue0.front();
        treeNodeQueue0.pop();
        nodeOther = treeNodeQueue1.front();
        treeNodeQueue1.pop();
        if (node != NULL && nodeOther != NULL)
        {
            if (node->val != nodeOther->val)
            {
                return false;
            }
            else
            {
                treeNodeQueue0.push(node->left);
                treeNodeQueue0.push(node->right);
                treeNodeQueue1.push(nodeOther->left);
                treeNodeQueue1.push(nodeOther->right);
            }
        }
        else if(node == NULL && nodeOther == NULL)
        {
        }
        else return false;
    }

    if (treeNodeQueue0.size() > 0)
        return false;

    return true;
}

bool BinaryTree::operator!=(const BinaryTree & tree) const
{
    return !(this->operator==(tree));
}

std::string BinaryTree::InOrderTravelsal()
{
    std::string result = "";
    std::stack<TreeNode* > treeNodeStack;
    TreeNode* cur = this->getRoot();

    while (cur || treeNodeStack.size() > 0)
    {
        if (cur)
        {
            treeNodeStack.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode* temp = treeNodeStack.top();
            treeNodeStack.pop();
            result += std::to_string(temp->val) + " ";
            cur = temp->right;
        }
    }
    return result;
}