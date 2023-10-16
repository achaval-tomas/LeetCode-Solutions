/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    struct ListNode* ans = malloc(sizeof(*ans));
    struct ListNode* ret = ans;
    struct ListNode* node = head;

    while (node != NULL){
        ans->val = node->val;
        node = (node->next != NULL) ? node->next->next : NULL;
        if (node != NULL){
            ans->next = malloc(sizeof(*ans));
            ans = ans->next;
        }
    }

    node = head->next;
    if (node != NULL){
        ans->next = malloc(sizeof(*ans));
        ans = ans->next;
    }

    while (node != NULL){
        ans->val = node->val;
        node = (node->next != NULL) ? node->next->next : NULL;
        if (node != NULL){
            ans->next = malloc(sizeof(*ans));
            ans = ans->next;
        }
    }

    ans->next = NULL;
    return ret;
}