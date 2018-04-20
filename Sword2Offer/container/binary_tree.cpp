#include <queue>
#include <stack>
#include <string>

#include "gtest/gtest.h"

#include "binary_tree.h"

BinaryTree::BinaryTree(std::initializer_list<int> list) : pRoot(NULL)
{
    if (list.size() <= 0 && *list.begin() != nonode)
        return;

    std::queue<TreeNode** > treeNodeQueue;
    auto it = list.begin();

    treeNodeQueue.push(&pRoot);

    while (it != list.end())
    {
        TreeNode** temp = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (*it != nonode)
        {
            (*temp) = new TreeNode(*it);
            treeNodeQueue.push(&((*temp)->left));
            treeNodeQueue.push(&((*temp)->right));
        }
        else
        {
            (*temp) = NULL;
            treeNodeQueue.push(NULL);
            treeNodeQueue.push(NULL);
        }
        it++;
    }
    return;
}

BinaryTree::~BinaryTree()
{
    if (pRoot == NULL)
        return;

    std::queue<TreeNode*> treeNodeQueue;
    treeNodeQueue.push(pRoot);
    while (treeNodeQueue.size() > 0)
    {
        TreeNode * temp = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (temp != NULL)
        {
            treeNodeQueue.push((temp->left));
            treeNodeQueue.push(temp->right);
            delete temp;
        }
    }
}

bool BinaryTree::operator==(const BinaryTree& tree) const
{
    TreeNode* pRootOther = tree.getRoot();
    std::queue<TreeNode*> treeNodeQueue0;
    std::queue<TreeNode*> treeNodeQueue1;

    treeNodeQueue0.push(pRoot);
    treeNodeQueue1.push(pRootOther);

    while (treeNodeQueue0.size() > 0)
    {
        TreeNode* node, *nodeOther;
        node = treeNodeQueue0.front();
        treeNodeQueue0.pop();
        nodeOther = treeNodeQueue1.front();
        treeNodeQueue1.pop();
        if (node != NULL && nodeOther != NULL)
        {
            if (node->val != nodeOther->val)
            {
                return false;
            }
            else
            {
                treeNodeQueue0.push(node->left);
                treeNodeQueue0.push(node->right);
                treeNodeQueue1.push(nodeOther->left);
                treeNodeQueue1.push(nodeOther->right);
            }
        }
        else if(node == NULL && nodeOther == NULL)
        {
        }
        else return false;
    }

    if (treeNodeQueue0.size() > 0)
        return false;

    return true;
}

TEST(BinaryTreeTest, InitBinaryTree)
{
    TreeNode* pRoot;
    BinaryTree binaryTree = {8, 10, 6, 11, 9, BinaryTree::nonode, 5};
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
    //BinaryTree binaryTree2 = { 8, 10, 6, 11, 9, BinaryTree::nonode, 5, 6 };
    //BinaryTree binaryTree3;

    EXPECT_EQ(binaryTree0, binaryTree1);
}

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
