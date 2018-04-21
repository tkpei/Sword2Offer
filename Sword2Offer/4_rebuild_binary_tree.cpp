#include <vector>

#include "gtest/gtest.h"

#include "common/log.h"
#include "container/binary_tree.h"

using std::vector;

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() != vin.size())
    {
        LOGF << "reConstructBinaryTree input error: size of pre != size of vin" << std::endl;
        LOGF << "size of pre: " << pre.size() << std::endl;
        LOGF << "size of vin: " << vin.size() << std::endl;
        return NULL;
    }

    if (pre.size() == 0 || vin.size() == 0)
    {
        return NULL;
    }

    TreeNode* node = new TreeNode(pre[0]);
    vector<int> preLeft;
    vector<int> vinLeft;
    vector<int> preRight;
    vector<int> vinRight;
    bool equal = false;
    for (auto it : vin)
    {
        if (it != pre[0] && !equal)
        {
            vinLeft.push_back(it);
        }
        else if (it == pre[0])
        {
            equal = true;
        }
        else
        {
            vinRight.push_back(it);
        }
    }
    for (int i = 1; i <= vinLeft.size(); i++)
    {
        preLeft.push_back(pre[i]);
    }
    for (size_t i = vinLeft.size() + 1; i < pre.size(); i++)
    {
        preRight.push_back(pre[i]);
    }

    node->left = reConstructBinaryTree(preLeft, vinLeft);
    node->right = reConstructBinaryTree(preRight, vinRight);

    return node;
}

TEST(reConstructBinaryTreeTest, Normal)
{
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* pRoot = reConstructBinaryTree(pre, vin);

    BinaryTree expectResult = { 1, 2, 3, 4, BinaryTree::nonode, 5, 6, BinaryTree::nonode, 7,
        BinaryTree::nonode, BinaryTree::nonode, BinaryTree::nonode, BinaryTree::nonode, 8 };

    EXPECT_EQ(BinaryTree(pRoot), expectResult);
}

TEST(reConstructBinaryTreeTest, NullNode) {}

TEST(reConstructBinaryTreeTest, OneNode) {}

TEST(reConstructBinaryTreeTest, TowNode) {}