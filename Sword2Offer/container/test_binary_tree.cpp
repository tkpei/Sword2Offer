#include "gtest/gtest.h"

#include "container/binary_tree.h"

class BinaryTreeTest : public ::testing::Test
{
protected:
    BinaryTreeTest() {}
    virtual ~BinaryTreeTest() {}
};

TEST(BinaryTreeTest, InitBinaryTree)
{
    TreeNode* pRoot;
    BinaryTree binaryTree = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5 };
    pRoot = binaryTree.getRoot();

    EXPECT_EQ(pRoot->val, 8);
    EXPECT_EQ(pRoot->left->val, 10);
    EXPECT_EQ(pRoot->right->val, 6);
    EXPECT_EQ(pRoot->left->left->val, 11);
    EXPECT_EQ(pRoot->left->right->val, 9);
    EXPECT_FALSE(pRoot->right->left);
    EXPECT_EQ(pRoot->right->right->val, 5);
}

TEST(BinaryTreeTest, OperatorEqual)
{
    BinaryTree binaryTree0 = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5 };
    BinaryTree binaryTree1 = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5 };
    BinaryTree binaryTree2 = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5, 6 };
    BinaryTree binaryTree3;

    EXPECT_EQ(binaryTree0, binaryTree1);
    EXPECT_NE(binaryTree0, binaryTree2);
    EXPECT_NE(binaryTree0, binaryTree3);
}

TEST(BinaryTreeTest, InOrderTravelsal)
{
    BinaryTree binaryTree0 = {8, 6, 10, 5, BinaryTree::nonode, 9, 11};
    BinaryTree binaryTree1;
    BinaryTree binaryTree2 = { 5 };
    BinaryTree binaryTree3 = { 9, 5 };

    EXPECT_EQ(binaryTree0.InOrderTravelsal(), "5 6 8 9 10 11 ");
    EXPECT_EQ(binaryTree1.InOrderTravelsal(), "");
    EXPECT_EQ(binaryTree2.InOrderTravelsal(), "5 ");
    EXPECT_EQ(binaryTree3.InOrderTravelsal(), "5 9 ");
}
