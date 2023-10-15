


typedef struct s_queue {
    int *vals;
    int size;
    int elems;
    int index;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = malloc(sizeof(*q));
    q->size = k;
    q->vals = malloc(sizeof(int)*k);
    q->elems = 0;
    q->index = 0;
    return q;
    
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->elems == obj->size)
        return false;
    ++obj->elems;
    obj->vals[(obj->index + obj->elems - 1) % obj->size] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
   if (obj->elems == 0)
        return false;
    obj->index = (obj->index+1) % obj->size;
    --obj->elems;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->elems == 0)
        return -1;
    return obj->vals[obj->index];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->elems == 0)
        return -1;
    return obj->vals[(obj->index + obj->elems - 1) % obj->size];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->elems == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->elems == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->vals);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/