


typedef struct sstack {
    int val;
    int size;
    int maxSize;
    struct sstack *next;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack = malloc(sizeof(CustomStack));
    stack->size = 0;
    stack->maxSize = maxSize;
    stack->next = NULL;
    return stack;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size == 0 && obj->maxSize > 0){
        obj->val = x;
        ++obj->size;
    } else if (obj->maxSize > obj->size) {
        CustomStack *stack = malloc(sizeof(CustomStack));
        stack->val = obj->val;
        stack->size = obj->size;
        stack->maxSize = obj->maxSize;
        stack->next = obj->next;
        obj->next = stack;
        obj->val = x;
        ++obj->size;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj == NULL || obj->size == 0)
        return -1;
    int val = obj->val;
    if (obj->size > 1){
        CustomStack* killme = obj->next;
        obj->val = obj->next->val;
        obj->next = obj->next->next;
        free(killme);
    } 
    --obj->size;
    return val;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int size = obj->size;
    int i = 0;
    while (i < size-k && obj != NULL){
        obj = obj->next;
        ++i;
    }
    while (obj != NULL){
        obj->val += val;
        obj = obj->next;
    }
}

void customStackFree(CustomStack* obj) {
    while (obj->size != 0){
        customStackPop(obj);
    }
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/