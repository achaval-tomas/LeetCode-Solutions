/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* ret = head;
    while (ret && ret->val == val){
        struct ListNode* killme = ret;
        ret = ret->next;
        free(killme);
    }
    head = ret;
    while (head && head->next ){
        while (head && head->next && head->next->val == val){
            struct ListNode* killme = head->next;
            head->next = head->next->next;
            free(killme);
        }
        head = head->next;
    }
    return ret;
}