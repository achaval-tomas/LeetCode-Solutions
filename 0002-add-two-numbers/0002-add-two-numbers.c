/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* res = malloc(sizeof(struct ListNode));

    res->val = l1->val + l2->val;
    res->next = NULL;
    struct ListNode* adder = res;

    l1 = l1->next; l2 = l2->next;

    while (l1 != NULL || l2 != NULL) {
        adder->next = malloc(sizeof(struct ListNode));
        adder = adder->next;
        if (l1 != NULL && l2 != NULL){
            adder->next = NULL;
            adder->val = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1 == NULL && l2 != NULL){
            adder->next = NULL;
            adder->val = l2->val;
            l2 = l2->next;
        } else if (l1 != NULL && l2 == NULL){
            adder->next = NULL;
            adder->val = l1->val;
            l1 = l1->next;
        } 

    }

    adder = res;
    int pass_on = 0;
    while (adder != NULL) {
        adder->val = adder->val + pass_on;
        pass_on = 0;
        if (adder->val >= 10){
            pass_on = 1;
            adder->val = adder->val - 10;
        }
        if (adder->next == NULL && pass_on){
            adder->next = malloc(sizeof(struct ListNode));
            adder = adder->next;
            adder->next = NULL;
            adder->val = pass_on;
        }
        adder = adder->next;
    }

    return res;
}