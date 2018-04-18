#include <vector>
#include <queue>

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

std::vector<int> PrintFromTopToBottom(TreeNode* root)
{
    std::queue<TreeNode*> queueContainer;
    std::vector<int> result;
    TreeNode* iCur;

    if (root == NULL)
        return result;

    queueContainer.push(root);
    while (queueContainer.size() > 0)
    {
        iCur = queueContainer.front();
        queueContainer.pop();
        result.push_back(iCur->val);
        if (iCur->left) queueContainer.push(iCur->left);
        if (iCur->right) queueContainer.push(iCur->right);
    }
    return result;
}

TEST(PrintFromTopToBottomTest, Normal)
{
    std::vector<int> result;
    std::vector<int> resultExpect = {8, 6, 10, 5, 9, 11};
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node6 = new TreeNode(6, node5, NULL);
    TreeNode *node10 = new TreeNode(10, node9, node11);
    TreeNode *node8 = new TreeNode(8, node6, node10);
    result = PrintFromTopToBottom(node8);
    EXPECT_EQ(result, resultExpect);
}


