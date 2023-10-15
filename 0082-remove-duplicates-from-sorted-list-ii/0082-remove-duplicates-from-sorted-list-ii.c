/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){

    struct ListNode* node = head;
    struct ListNode* prevNode = node;

    while (node != NULL){
        bool dup = false;
        
        while (node->next != NULL && node->next->val == node->val){
            struct ListNode* killme = node->next;
            node->next = node->next->next;
            free(killme);
            dup = true;
        }
        if (dup){
            if (node->next != NULL) {
                node->val = node->next->val;
                struct ListNode* killme1 = node->next;
                node->next = node->next->next;
                free(killme1);
            } else {
                if (prevNode == node)
                    return NULL;
                prevNode->next = NULL;
                node = NULL;
            }
        } else {
            prevNode = node;
            node = node->next;
        }
    }

    return head;
}