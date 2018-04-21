#include <vector>

#include "gtest/gtest.h"

#include "container/binary_tree.h"

using std::vector;

vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
{
    if (root == NULL)
    {
        return vector<vector<int> >();
    }
    else
    {
        vector<vector<int> > result;
        int expect = expectNumber - root->val;
        if (expect == 0 && !root->left && !root->right)
        {
            result.push_back(vector<int>());
            result[0].push_back(root->val);
            return result;
        }
        else if(expect <= 0)
        {
            return result;
        }
        vector<vector<int> > resultLeft = FindPath(root->left, expect);
        vector<vector<int> > resultRight = FindPath(root->right, expect);
        for (auto it : resultLeft)
        {
            result.push_back(vector<int>());
            (*(result.end() - 1)).push_back(root->val);
            for (auto itr : it)
            {
                (*(result.end() - 1)).push_back(itr);
            }
        }
        for (auto it : resultRight)
        {
            result.push_back(vector<int>());
            (*(result.end() - 1)).push_back(root->val);
            for (auto itr : it)
            {
                (*(result.end() - 1)).push_back(itr);
            }
        }
        return result;
    }
}

TEST(BinaryTreeFindPathTest, Normal)
{
    BinaryTree tree = {10, 5, 12, 8, 7};
    vector<vector<int> > resultExpect = { {10, 5, 7},{10, 12} };
    vector<vector<int> > result;

    result = FindPath(tree.getRoot(), 22);
    EXPECT_EQ(result, resultExpect);
}