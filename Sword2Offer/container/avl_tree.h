#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <climits>
#include <initializer_list>
#include <algorithm>

struct AVLNode
{
    int val_;
    AVLNode* leftTree_;
    AVLNode* rightTree_;
    int height_;

    AVLNode(int val, int height, AVLNode* leftTree, AVLNode* rightTree)
        : val_(val), height_(height), leftTree_(leftTree), rightTree_(rightTree) {}

    static void updateHeight(AVLNode* node)
    {
        node->height_ = std::max(getHeight(node->leftTree_), getHeight(node->rightTree_)) + 1;
    }

    static int getHeight(AVLNode* node)
    {
        if (node == NULL)
            return 0;
        else return node->height_;
    }
};

class AVLTree
{
public:
    static const int nonode = INT_MAX;

    AVLTree() : root_(NULL) {};

    AVLTree(AVLNode* root) : root_(root) {};

    AVLTree(std::initializer_list<int> list);

    void insert(int value);

    AVLNode* getRoot() const { return root_; }

    AVLNode* getRoot() { return root_; }
private:

    AVLNode* root_;
};

#endif // __AVL_TREE__