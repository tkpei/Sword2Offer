#include <vector>
#include <queue>

#include "gtest/gtest.h"

#include "container/binary_tree.h"

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
    BinaryTree tree = { 8, 6, 10, 5, BinaryTree::nonode, 9, 11 };
    std::vector<int> resultExpect = {8, 6, 10, 5, 9, 11};
    std::vector<int> result;

    result = PrintFromTopToBottom(tree.getRoot());

    EXPECT_EQ(result, resultExpect);
}


