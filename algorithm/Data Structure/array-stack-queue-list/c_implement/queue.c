#include <stdio.h>
#include <stdlib.h>

const int INIT_STACK_SIZE = 16;

typedef struct {
    int head;
    int tail;
    int maxSize;
    int *array;
} Queue;

void QueueInit(Queue *q)
{
    q->head = 0;
    q->tail = 0;

    q->maxSize = INIT_STACK_SIZE;
    q->array = (int *)malloc(sizeof(int) * q->maxSize);
}

void QueuePush(Queue *q, int item)
{
    if ((q->tail + 1) % (q->maxSize) == q->head)
    {
        printf("q full\n");
        return;
    }

    q->array[q->tail] = item;
    q->tail = (q->tail + 1) % (q->maxSize);
}

int QueueEmpty(Queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    return 0;
}

int QueuePop(Queue *q)
{
    if (QueueEmpty(q))
    {
        printf("q empty\n");
        return -1;
    }

    int result = q->array[q->head];
    q->head = (q->head + 1) % (q->maxSize);
    
    return result;
}

int main()
{
    Queue s;
    int a[20] = {1,2,3,4,5};
    QueueInit(&s);
    for (size_t i = 0; i < 10; i++)
    {
        QueuePush(&s, a[i]);
        printf("head %d, tail %d\n", s.head, s.tail);
    }

    for (size_t i = 0; i < 11; i++)
    {
        printf("%d\n", QueuePop(&s));
        printf("head %d, tail %d\n", s.head, s.tail);
    }
    
    for (size_t i = 0; i < 20; i++)
    {
        QueuePush(&s, a[i]);
        printf("head %d, tail %d\n", s.head, s.tail);
    }

    return 0;
}
