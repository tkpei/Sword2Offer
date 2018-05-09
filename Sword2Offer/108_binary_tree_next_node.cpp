#include "gtest/gtest.h"

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

TreeLinkNode* getNext(TreeLinkNode* pNode)
{
    if (pNode == NULL)
        return NULL;

    /* 右节点为NULL，且有父节点 */
    if (pNode->right == NULL && pNode->next != NULL)
    {
        TreeLinkNode* pTempNode = pNode;
        TreeLinkNode* pParent = pNode->next;
        while (pParent->left != pTempNode)
        {
            if (pParent->next != NULL)
            {
                pTempNode = pParent;
                pParent = pParent->next;
            }
            else
                return NULL;
        }
        return pParent;
    }
    /* 右节点为NULL，且没有父节点 */
    else if (pNode->right == NULL && pNode->next == NULL)
        return NULL;
    /* 右节点不为null */
    else
    {
        TreeLinkNode* pTempNode = pNode->right;
        while (pTempNode->left != NULL)
            pTempNode = pTempNode->left;
        return pTempNode;
    }
}