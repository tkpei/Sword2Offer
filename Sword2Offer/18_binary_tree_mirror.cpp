#include "gtest/gtest.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) :
        val(x), left(leftNode), right(rightNode) {}
};

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
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node6 = new TreeNode(6, node5, NULL);
    TreeNode *node10 = new TreeNode(10, node9, node11);
    TreeNode *node8 = new TreeNode(8, node6, node10);
    Mirror(node8);

    EXPECT_EQ(node8->val, 8);
    EXPECT_EQ(node8->left->val, 10);
    EXPECT_EQ(node8->right->val, 6);
    EXPECT_EQ(node8->left->left->val, 11);
    EXPECT_EQ(node8->left->right->val, 9);
    EXPECT_FALSE(node8->right->left);
    EXPECT_EQ(node8->right->right->val, 5);
}

TEST(MirrorTest, NULLNode)
{
    TreeNode *node = NULL;
    Mirror(node);

    EXPECT_FALSE(node);
}
