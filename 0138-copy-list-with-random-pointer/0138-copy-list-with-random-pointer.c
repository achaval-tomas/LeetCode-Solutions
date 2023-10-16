/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
int listlen(struct Node *l){
    return (l == NULL) ? 0 : 1+listlen(l->next);
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    int len = listlen(head);
    struct Node *random[len];
    int j = 0;

	struct Node* ans = malloc(sizeof(*ans));
    struct Node* ret = ans;
    struct Node* node = head;
    while (node != NULL){
        ans->val = node->val;
        random[j++] = node->random;
        node = node->next;
        if (node != NULL){
            ans->next = malloc(sizeof(*ans));
            ans = ans->next;
        } else {
            ans->next = NULL;
        }
    }
    j = 0;
    node = ret;
    for (int i = 0; i<len; ++i){
        struct Node *help = ret;
        struct Node *help2 = head;
        while (help2 != random[j]){
            help = help->next;
            help2 = help2->next;
        }
        node->random = random[j++] != NULL ? help : NULL;
        node = node->next;
    }

    return ret;
}