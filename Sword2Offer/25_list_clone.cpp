#include <vector>

#include "gtest/gtest.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* clone(RandomListNode* pHead)
{
    if (pHead == NULL)
        return NULL;

    for (RandomListNode* pointer = pHead; pointer != NULL;)
    {
        RandomListNode* copyElement = new RandomListNode(pointer->label);
        copyElement->next = pointer->next;
        pointer->next = copyElement;
        pointer = copyElement->next;
    }

    for (RandomListNode* pointer = pHead; pointer != NULL;)
    {
        RandomListNode* copyElement = pointer->next;
        copyElement->random = pointer->random->next;
        pointer = copyElement->next;
    }

    RandomListNode* result = pHead->next;
    for (RandomListNode* pointer = pHead; pointer != NULL;)
    {
        RandomListNode* copyElement = pointer->next;
        pointer->next = copyElement->next;
        if (copyElement->next != NULL)
        {
            copyElement->next = copyElement->next->next;
        }
        else copyElement->next = NULL;
        pointer = pointer->next;
    }

    return result;
}

TEST(CloneTest, Normal)
{
    RandomListNode* copyElement1 = new RandomListNode(1);
    RandomListNode* copyElement2 = new RandomListNode(2);
    RandomListNode* copyElement3 = new RandomListNode(3);

    copyElement1->next = copyElement2;
    copyElement2->next = copyElement3;
    copyElement1->random = copyElement3;
    copyElement2->random = copyElement3;
    copyElement3->random = copyElement1;

    clone(copyElement1);
}