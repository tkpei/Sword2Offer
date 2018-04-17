#include <stack>
#include <string>

#include "gtest/gtest.h"

#include "binary_tree.h"


/* 二叉树的非递归中序遍历 */
std::string InOrderTravelsal(TreeNode* pRoot)
{
    std::string result = "";
    std::stack<TreeNode* > treeNodeStack;
    TreeNode* cur = pRoot;

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

TEST(BinaryTreeTest, Normal)
{
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node6 = new TreeNode(6, node5, NULL);
    TreeNode *node10 = new TreeNode(10, node9, node11);
    TreeNode *node8 = new TreeNode(8, node6, node10);
    std::string result = InOrderTravelsal(node8);
    EXPECT_EQ(result, "5 6 8 9 10 11 ");
}

TEST(BinaryTreeTest, NULLNode)
{
    TreeNode *node = NULL;

    std::string result = InOrderTravelsal(node);
    EXPECT_EQ(result, "");
}

TEST(BinaryTreeTest, OneNode)
{
    TreeNode *node = new TreeNode(5);

    std::string result = InOrderTravelsal(node);
    EXPECT_EQ(result, "5 ");
}

TEST(BinaryTreeTest, TwoNode)
{
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(9, node5, NULL);

    std::string result = InOrderTravelsal(node9);
    EXPECT_EQ(result, "5 9 ");
}