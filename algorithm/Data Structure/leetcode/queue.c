#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int *data;
    int head;
    int tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    k = k + 1;
    MyCircularQueue *q = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    q->size = k;
    q->data = (int*)malloc(sizeof(int) * k);
    q->head = 0;
    q->tail = 0;
    return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->size;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    
    obj->head = (obj->head + 1) % obj->size;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }

    return obj->data[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    
    return obj->data[(obj->tail - 1 + obj->size) % obj->size];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->head == obj->tail) {
        return true;
    }

    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->tail + 1) % (obj->size) == obj->head) {
        return true;
    }
    
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) {
        return;
    }
    
    if (obj->data != NULL) {
        free(obj->data);
        obj->data = NULL;
    }
    
    if (obj != NULL) {
        free(obj);
        obj = NULL;
    }
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