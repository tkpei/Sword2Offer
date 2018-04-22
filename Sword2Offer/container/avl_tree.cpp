#include "avl_tree.h"

AVLTree::AVLTree(std::initializer_list<int> list)
{
    if (list.size() <= 0 && *list.begin() != nonode)
        return;
    for (auto it : list)
    {
        insert(it);
    }
}

namespace
{
    AVLNode* singleLeftRotation(AVLNode* input)
    {
        AVLNode* result;
        result = input->leftTree_;
        input->leftTree_ = NULL;
        result->rightTree_ = input;
        AVLNode::updateHeight(input);
        AVLNode::updateHeight(result);
        return result;
    }

    AVLNode* singleRightRotation(AVLNode* input)
    {
        AVLNode* result;
        result = input->rightTree_;
        input->rightTree_ = NULL;
        result->leftTree_ = input;
        AVLNode::updateHeight(input);
        AVLNode::updateHeight(result);
        return result;
    }

    AVLNode* leftRightRotation(AVLNode* input)
    {
        input->leftTree_ = singleRightRotation(input->leftTree_);
        return singleLeftRotation(input);
    }

    AVLNode* rightLeftRotation(AVLNode* input)
    {
        input->rightTree_ = singleLeftRotation(input->rightTree_);
        return singleRightRotation(input);
    }

    AVLNode* insertImp(AVLNode* root, int value)
    {
        if (root == NULL)
        {
            root = new AVLNode(value, 1, NULL, NULL);
        }
        else if (value < root->val_)
        {
            root->leftTree_ = insertImp(root->leftTree_, value);
            if (AVLNode::getHeight(root->leftTree_) - AVLNode::getHeight(root->rightTree_) == 2)
            {
                if (value < root->leftTree_->val_)
                    root = singleLeftRotation(root);
                else root = leftRightRotation(root);
            }
        }
        else if (value > root->val_)
        {
            root->rightTree_ = insertImp(root->rightTree_, value);
            if (AVLNode::getHeight(root->leftTree_) - AVLNode::getHeight(root->rightTree_) == -2)
            {
                if (value < root->rightTree_->val_)
                    root = singleRightRotation(root);
                else root = rightLeftRotation(root);
            }
        }

        AVLNode::getHeight(root);
        return root;
    }
}

void AVLTree::insert(int value)
{
    root_ = insertImp(root_, value);
}