#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <climits>
#include <initializer_list>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) :
        val(x), left(leftNode), right(rightNode) {}
};

class BinaryTree
{
public:
    static const int nonode = INT_MAX;

    BinaryTree() : pRoot(NULL) {};

    BinaryTree(std::initializer_list<int> list);

    BinaryTree(const BinaryTree& other);

    BinaryTree& operator= (const BinaryTree& other);

    ~BinaryTree();

    bool operator==(const BinaryTree& tree) const;

    TreeNode* getRoot() const { return pRoot; }

private:
    TreeNode* pRoot;
};

#endif // __BINARY_TREE__