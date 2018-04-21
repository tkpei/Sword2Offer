#include "gtest/gtest.h"

#include "container/binary_tree.h"

void Mirror(TreeNode *pRoot)
{
    if (pRoot)
    {
        TreeNode *temp;
        temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
    return;
}

TEST(MirrorTest, MirrorNormal)
{
    BinaryTree tree = { 8, 6, 10, 5, BinaryTree::nonode, 9, 11 };
    BinaryTree treeExpect = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5 };

    Mirror(tree.getRoot());

    EXPECT_EQ(tree, treeExpect);
}
