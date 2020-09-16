#include "stdlib.h"
#include "string.h"

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node
{
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

#define MAX_NUM 101

struct Node *cloned[MAX_NUM] = {0};

struct Node *cloneFunc(struct Node *s)
{
    if (s == NULL)
    {
        return NULL;
    }

    struct Node *d = (struct Node *)malloc(sizeof(struct Node));
    d->val = s->val;
    d->numNeighbors = s->numNeighbors;
    cloned[s->val] = d;
    if (d->numNeighbors == 0)
    {
        return d;
    }

    d->neighbors = (struct Node *)malloc(sizeof(struct Node *) * d->numNeighbors);
    for (size_t i = 0; i < s->numNeighbors; i++)
    {
        int val = s->neighbors[i]->val;
        if (cloned[val] != 0)
        {
            d->neighbors[i] = cloned[val];
        }
        else
        {
            d->neighbors[i] = cloneFunc(s->neighbors[i]);
        }
    }

    return d;
}

struct Node *cloneGraph(struct Node *s)
{

    memset(cloned, 0, sizeof(struct Node *) * MAX_NUM);
    return cloneFunc(s);
}