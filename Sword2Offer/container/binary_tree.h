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

    BinaryTree() : pRoot_(NULL) {};

    BinaryTree(TreeNode* pRoot) : pRoot_(pRoot) {};

    BinaryTree(std::initializer_list<int> list);

    BinaryTree(const BinaryTree& other);

    ~BinaryTree();

    BinaryTree& operator= (const BinaryTree& other);

    bool operator==(const BinaryTree& tree) const;

    bool operator!=(const BinaryTree& tree) const;

    std::string InOrderTravelsal();

    TreeNode* getRoot() const { return pRoot_; }

    TreeNode* getRoot() { return pRoot_; }

private:
    TreeNode* pRoot_;
};

#endif // __BINARY_TREE__