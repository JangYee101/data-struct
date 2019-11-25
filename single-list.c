//title num:237

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


void deleteNodeByVal(struct ListNode *ptr, int val)
{
    while(ptr->next != NULL)
    {
        if(ptr->next->val == val)
        {
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

void deleteNode(struct ListNode *node)
{
    if(node->next == NULL)
    {
        node = NULL;
        return;
    }
    node->val = node->next->val;
    node->next = node->next->next;
    return;
}

void creatNode(struct ListNode **ptr, int *data, int data_length)
{
    struct ListNode *p_LN, *p_temp;
    *ptr = calloc(1, sizeof(struct ListNode));
    (*ptr)->val = *data++;
    (*ptr)->next = NULL;
    //data_length--;
    p_LN = *ptr;
    while(--data_length)
    {
        p_temp = calloc(1, sizeof(struct ListNode));
        p_temp->val = *data++;
        p_temp->next = NULL;
        p_LN->next = p_temp;
        p_LN = p_LN->next;
    }
    return;
}

void traversNode(struct ListNode *ptr)
{
    while(ptr != NULL)
    {

        printf("%d\n", ptr->val);
        if(ptr->val == 0) break;
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void addNode(struct ListNode *ptr, int val, int site)
{
    while(--site)
    {
        ptr = ptr->next;
    }
    struct ListNode *p_temp = calloc(1, sizeof(struct ListNode));
    p_temp->val = val;
    p_temp->next = ptr->next;
    ptr->next = p_temp;
    return;
}

int main()
{
    struct ListNode *ptr;
    int data[10]={34,3,5,7,9,2,4,6,8,0};
    creatNode(&ptr, data, 10);
    traversNode(ptr);
    deleteNodeByVal(ptr, 5);
    traversNode(ptr);
    deleteNode(ptr);
    traversNode(ptr);
    addNode(ptr, 1314, 2);
    traversNode(ptr);
    return 0;
}
