/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listlen(struct ListNode* l){
    return (l==NULL) ? 0 : 1+listlen(l->next);
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (k == 0)
        return head;
    int len = listlen(head);
    if (len == 0)
        return len;
    int leftlen = k%len;
    int left[leftlen == 0 ? 1 : leftlen];
    int right[len-leftlen];

    struct ListNode *node = head;
    for (int i = 0; i<len-leftlen;++i){
        right[i] = node->val;
        node = node->next;
    }
    for (int i = 0; i<leftlen;++i){
        left[i] = node->val;
        node = node->next;
    }
    node = head;
    for (int i = 0; i<leftlen;++i){
        node->val = left[i];
        node = node->next;
    }
    for (int i = 0; i<len-leftlen;++i){
        node->val = right[i];
        node = node->next;
    }

    return head;
}