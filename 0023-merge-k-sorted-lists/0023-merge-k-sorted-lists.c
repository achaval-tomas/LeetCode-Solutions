/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listlen(struct ListNode *list){
    return (list == NULL) ? 0 : 1+listlen(list->next);
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
        return NULL;
    int lengths[listsSize];
    int currentIndex[listsSize];
    int total = 0;
    for (int i = 0; i<listsSize; ++i){
        lengths[i] = listlen(lists[i]);
        total += lengths[i];
        currentIndex[i] = 0;
    }
    if (total == 0)
        return NULL;

    struct ListNode* result = malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;
    struct ListNode* ans = result;
    struct ListNode* killme = result->next;
    for (int i = 0; i<total; ++i){
        int min = INT_MAX;
        int usedList = 0;
        for (int j = 0; j<listsSize;++j){
            if (currentIndex[j] < lengths[j] && lists[j]->val < min){
                usedList = j;
                min = lists[j]->val;
            }
        }
        lists[usedList] = lists[usedList]->next;
        ++currentIndex[usedList];
        result->val = min;
        result->next = malloc(sizeof(struct ListNode));
        killme = result;
        result = result->next;
    }
    free(killme->next);
    killme->next = NULL;
    return ans;
}