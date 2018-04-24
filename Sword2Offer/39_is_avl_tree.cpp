#include <algorithm>
#include <limits.h>

#include "gtest/gtest.h"

#include "container/binary_tree.h"

bool isAVLTree(TreeNode* pRoot, int maxNum, int minNum, int& depth)
{
    if (pRoot == NULL)
    {
        depth = 0;
        return true;
    }

    int depthLeft, depthRight;
    int result;

    if (pRoot->val >= maxNum || pRoot->val <= minNum)
        return false;

    result = isAVLTree(pRoot->left, pRoot->val, minNum, depthLeft);
    if (result == false)
        return false;
    result = isAVLTree(pRoot->right, maxNum, pRoot->val, depthRight);
    if (result == false)
        return false;

    if (abs(depthLeft - depthRight) >= 2)
        return false;

    depth = std::max(depthLeft, depthRight) + 1;
    return true;
}

bool IsBalancedSolution(TreeNode* pRoot)
{
    int depth;
    return isAVLTree(pRoot, INT_MAX, INT_MIN, depth);
}

TEST(isAVLTreeTest, Normal)
{
    BinaryTree tree0 = { 10, 5, 15, 1, 6, 12, 16, BinaryTree::nonode, 3};
    BinaryTree tree1 = { 10, 5, 15, 1, 6, BinaryTree::nonode, BinaryTree::nonode,
                         BinaryTree::nonode, 3 };

    EXPECT_EQ(IsBalancedSolution(tree0.getRoot()), true);
    EXPECT_EQ(IsBalancedSolution(tree1.getRoot()), false);
}