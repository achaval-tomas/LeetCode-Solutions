/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcdiv(int a, int b){
    int i = a < b ? a : b;
    while (i>1 && (a%i || b%i)){
        --i;
    }
    return i;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* node = head;
    while (node->next != NULL){
        int gcd = gcdiv(node->val, node->next->val);
        struct ListNode* newNode = malloc(sizeof(*newNode));
        newNode->val = gcd;
        newNode->next = node->next;
        node->next = newNode;
        node = newNode->next;
    }
    return head;
}