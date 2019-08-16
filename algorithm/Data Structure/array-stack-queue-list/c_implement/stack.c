#include <stdio.h>
#include <stdlib.h>

const int INIT_STACK_SIZE = 16;

typedef struct {
    int size;
    int maxSize;
    int *array;
} Stack;

void StackInit(Stack *stack)
{
    stack->size = 0;
    stack->maxSize = INIT_STACK_SIZE;
    stack->array = (int *)malloc(sizeof(int) * stack->maxSize);
}

void StackPush(Stack *stack, int item)
{
    if (stack->size == stack->maxSize)
    {
        printf("stack full\n");
        return;
    }
    
    stack->array[stack->size] = item;
    stack->size++;
}

int StackEmpty(Stack *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }
    return 0;
}

int StackPop(Stack *stack)
{
    if (StackEmpty(stack))
    {
        printf("stack empty\n");
        return -1;
    }
    
    stack->size --;
    return stack->array[stack->size];
}

int main()
{
    Stack s;
    int a[20] = {1,2,3,4,5};
    StackInit(&s);
    for (size_t i = 0; i < 10; i++)
    {
        StackPush(&s, a[i]);
    }

    for (size_t i = 0; i < 11; i++)
    {
        printf("%d\n", StackPop(&s));
    }
    
    for (size_t i = 0; i < 20; i++)
    {
        StackPush(&s, a[i]);
    }

    return 0;
}
