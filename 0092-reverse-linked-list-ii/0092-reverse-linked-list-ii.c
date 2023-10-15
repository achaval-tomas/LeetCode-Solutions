/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    int lgt = right-left+1;
    if (lgt <= 1)
        return head;
    int arr[lgt];
    struct ListNode* waiter = head;
    struct ListNode* collector = head;
    int i = 0;
    while (i<left-1 && collector != NULL && waiter != NULL){
        collector = collector->next;
        waiter = waiter->next;
        ++i;
    }
    for (int j = 0; j<lgt && collector != NULL; ++j){
        arr[lgt-1-j] = collector->val;
        collector = collector->next;
    }
    for (int j = 0; j<lgt && waiter != NULL; ++j){
        waiter->val = arr[j];
        waiter = waiter->next;
    }

    return head;
}