


typedef struct mstack {
    int val;
    int min;
    struct mstack* next;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->next = obj;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->next == obj){
        obj->val = val;
        obj->min = val;
        obj->next = NULL;
    } else {
        MinStack* newScnd = malloc(sizeof(MinStack));
        newScnd->val = obj->val;
        newScnd->min = obj->min;
        newScnd->next = obj->next;
        obj->next = newScnd;
        obj->val = val;
        obj->min = (val < newScnd->min) ? val : newScnd->min;
        printf("%d ", val);
    }
  
}

void minStackPop(MinStack* obj) {
    if (obj->next != obj && obj->next != NULL) {
        MinStack *killme = obj->next;
        obj->val = obj->next->val;
        obj->min = obj->next->min;
        obj->next = obj->next->next;
        free(killme);
    } else {
        obj->next = obj;
    }
}

int minStackTop(MinStack* obj) {
    return (obj == NULL) ? 0 : obj->val;
}

int minStackGetMin(MinStack* obj) {
    return (obj == NULL) ? 0 : obj->min;
}

void minStackFree(MinStack* obj) {
    while (obj != obj->next){
        minStackPop(obj);
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/