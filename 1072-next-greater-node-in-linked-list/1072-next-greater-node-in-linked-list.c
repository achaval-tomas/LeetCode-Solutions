/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int listlen(struct ListNode* l){
    return (l==NULL) ? 0 : 1 + listlen(l->next);
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int len = listlen(head);
    *returnSize = len;
    int *ans = malloc(len*sizeof(*ans));

    for (int i = 0; i<len; ++i){
        int val = head->val;
        struct ListNode* node = head;
        while (node != NULL && node->val <= val)
            node = node->next;
        ans[i] = node ? node->val : 0;
        head = head->next;
    }
    return ans;
}