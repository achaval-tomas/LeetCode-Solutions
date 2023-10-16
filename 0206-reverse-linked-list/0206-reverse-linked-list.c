/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listlen(struct ListNode * l){
    return (l==NULL) ? 0 : 1+listlen(l->next);
}

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    int len = listlen(head);
    int ans[len];
    struct ListNode *node = head;
    for (int i = 1; i<=len ; ++i){
        ans[len - i] = node->val;
        node = node->next;
    }
    node = head;
    for (int i = 0; i<len; ++i){
        node->val = ans[i];
        node = node->next;
    }

    return head;
}