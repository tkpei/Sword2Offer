#include "gtest/gtest.h"

#define PT_EC_FAIL  -1

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int loopNodeNum(ListNode* pHead)
{
    if (pHead == NULL)
        return PT_EC_FAIL;
    ListNode* pLow = pHead, *pFast = pHead->next;
    while (pLow != pFast)
    {
        if (pLow != NULL)
            pLow = pLow->next;
        else return PT_EC_FAIL;
        if (pFast != NULL)
            pFast = pFast->next;
        else return PT_EC_FAIL;
        if (pFast != NULL)
            pFast = pFast->next;
        else return PT_EC_FAIL;
    }
    ListNode* pTemp = pLow;
    pLow = pLow->next;
    int result = 1;
    while (pLow != pTemp)
    {
        result++;
        pLow = pLow->next;
    }
    return result;
}

ListNode* entryNodeOfLoop(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;

    int loopNum = loopNodeNum(pHead);
    if (loopNum == PT_EC_FAIL)
        return NULL;

    ListNode* pFirst = pHead;
    ListNode* pLast = pHead;
    for (int i = 0; i < loopNum; i++)
    {
        pFirst = pFirst->next;
    }
    while (pFirst != pLast)
    {
        pFirst = pFirst->next;
        pLast = pLast->next;
    }
    return pFirst;
}