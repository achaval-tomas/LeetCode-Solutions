/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverseBetween(struct ListNode* head, int left, int right){
    int lgt = right-left+1;
    if (lgt <= 1)
        return;
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
}

int listlen(struct ListNode* head){
    return (head == NULL) ? 0 : 1+listlen(head->next);
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int start = 1;
    int end = k;
    int len = listlen(head);
    while (end <= len){
        reverseBetween(head, start, end);
        start = end+1;
        end += k;
    }
    return head;
}