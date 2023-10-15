/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listLength(struct ListNode* head){
    if (head == NULL)
        return 0;
    if (head->next == NULL)
        return 1;
    return 1+listLength(head->next);
}

int pairSum(struct ListNode* head){
    int length = listLength(head);
    struct ListNode* first = head;
    struct ListNode* second = head;

    for (int i = 0; i<length/2; ++i){
        second = second->next;
    }
    int half1[length/2];
    int half2[length/2];
    for (int i = 0; i<length/2; ++i){
        half1[i] = first->val;
        first = first->next;
    }
    for (int i = 0; i<length/2; ++i){
        half2[(int)(length/2)-1-i] = second->val;
        second = second->next;
    }
    int max = INT_MIN;
    for (int i = 0; i<length/2; ++i){
        int sum = half1[i] + half2[i];
        if (sum > max)
            max = sum;
    }

    return max;
}