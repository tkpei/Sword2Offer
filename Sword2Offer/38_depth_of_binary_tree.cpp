#include <algorithm>

#include "gtest/gtest.h"

#include "container/binary_tree.h"

int TreeDepth(TreeNode* pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
}

TEST(TreeDepthTest, Normal)
{
    BinaryTree tree0 = { 10, 5, 12, 8, 7};
    BinaryTree tree1 = { 10, 5, 12, 8, 7, BinaryTree::nonode, BinaryTree::nonode, 1};

    EXPECT_EQ(TreeDepth(tree0.getRoot()), 3);
    EXPECT_EQ(TreeDepth(tree1.getRoot()), 4);
}