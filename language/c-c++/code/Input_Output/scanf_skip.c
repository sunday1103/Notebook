#include <stdio.h>
#include <string.h>

#define MAX_NODE_NUM 100
#define MAX_STR_LEN 100
#define MAX_QUERY_NUM 10

int g_map[MAX_NODE_NUM][MAX_NODE_NUM];

int g_nodeNum;
char g_nodeNames[MAX_NODE_NUM][MAX_STR_LEN];

int g_queryNum;
int g_queryNode[MAX_QUERY_NUM][2];

int GetNodeIndex(char *s)
{
    for (size_t i = 0; i < g_nodeNum; i++)
    {
        if (strcmp(g_nodeNames[i], s) == 0)
        {
            return i;
        }   
    }
    
    return -1;
}

void Input()
{
    scanf("%d", &g_nodeNum);
    for (size_t i = 0; i < g_nodeNum; i++)
    {
        scanf("%s", g_nodeNames[i]);
    }

    int connectNum;
    scanf("%d", &connectNum);
    for (size_t i = 0; i < connectNum; i++)
    {
        char str1[MAX_STR_LEN] = {0};
        char str2[MAX_STR_LEN] = {0};
        scanf("%*[\r\n]%[^+]%*c%s", str1, str2);

        int index1 = GetNodeIndex(str1);
        int index2 = GetNodeIndex(str2);
        
        g_map[index1][index2] = 1;
        g_map[index2][index1] = 1;
    }

    scanf("%d", &g_queryNum);
    for (size_t i = 0; i < g_queryNum; i++)
    {
        char str1[MAX_STR_LEN] = {0};
        char str2[MAX_STR_LEN] = {0};
        scanf("%*[\r\n]%[^?]%*c%s", str1, str2);

        int index1 = GetNodeIndex(str1);
        int index2 = GetNodeIndex(str2);

        g_queryNode[i][0] = index1;
        g_queryNode[i][1] = index2;
    }
}

#define MAX_QUEUE_LEN MAX_NODE_NUM
typedef struct
{
    int head;
    int tail;
    int content[MAX_QUEUE_LEN];
}Queue;

void QueueInit(Queue *q)
{
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(Queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    
    return 0;
}

int QueueFull(Queue *q)
{
    if ((q->tail + 1) % MAX_QUEUE_LEN == q->head)
    {
        return 1;
    }
    
    return 0;
}

void QueuePush(Queue *q, int v)
{
    if (QueueFull(q))
    {
        return;
    }
    
    q->content[q->tail] = v;
    q->tail = (q->tail + 1) % MAX_QUEUE_LEN;
}

int QueuePop(Queue *q)
{
    if(QueueEmpty(q))
    {
        return -1;
    }
    int v = q->content[q->head];
    q->head = (q->head + 1) % MAX_QUEUE_LEN;
    return v;
}

int GetShortDist(int src, int dst)
{
    int dist[MAX_NODE_NUM];
    for (size_t i = 0; i < g_nodeNum; i++)
    {
        dist[i] = -1;
    }
    
    Queue q;
    QueueInit(&q);

    QueuePush(&q, src);
    dist[src] = 0;

    while (!QueueEmpty(&q))
    {
        int handleNode = QueuePop(&q);
        for (size_t i = 0; i < g_nodeNum; i++)
        {
            if (g_map[handleNode][i] == 1 && dist[i] == -1)
            {
                dist[i] = dist[handleNode] + 1;
                QueuePush(&q, i);
                if (i == dst)
                {
                    return dist[i];
                }
                
            }
        }
    }

    return -1;
}

void Process()
{
    for (size_t i = 0; i < g_queryNum; i++)
    {
        printf("%d\n", GetShortDist(g_queryNode[i][0], g_queryNode[i][1]));
    }   
}

int main()
{
    //freopen("input.txt","r",stdin);
    Input();
    Process();

    return 0;
}