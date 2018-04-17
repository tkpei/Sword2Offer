#ifndef __BINARY_TREE__
#define __BINARY_TREE__

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) :
        val(x), left(leftNode), right(rightNode) {}
};

#endif // __BINARY_TREE__