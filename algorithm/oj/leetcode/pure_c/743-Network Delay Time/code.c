#include "stdio.h"
#include "stdlib.h"

#define MAX_NUM 101

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    int distance[MAX_NUM] = {0};
    int visited[MAX_NUM] = {0};
    for (size_t i = 1; i <= N; i++)
    {
        distance[i] = -1;
    }
    int map[MAX_NUM][MAX_NUM] = {0};
    for (size_t i = 0; i < MAX_NUM; i++)
    {
        for (size_t j = 0; j < MAX_NUM; j++)
        {
            map[i][j] = -1;
        }
        
    }
    
    for (size_t i = 0; i < timesSize; i++)
    {
        int src = times[i][0];
        int dst = times[i][1];
        int value = times[i][2];
        map[src][dst] = value;
    }
    

    distance[K] = 0;
    for (size_t i = 1; i <= N; i++)
    {
        int next;
        int minV = -1;
        for (size_t j = 1; j <= N; j++)
        {
            if (visited[j] == 1 || distance[j] == -1)
            {
                continue;
            }
            if (minV == -1 || distance[j] < minV)
            {
                minV = distance[j];
                next = j;
            }
        }

        visited[next] = 1;
        for (size_t i = 1; i <= N; i++)
        {
            if (map[next][i] == -1)
            {
                continue;
            }
            if (distance[i] == -1 || distance[i] > distance[next] + map[next][i])
            {
                distance[i] = distance[next] + map[next][i];
            }
        }
    }
    
    int maxValue = -1;
    for (size_t i = 1; i <= N; i++)
    {
        if (distance[i] == -1)
        {
            return -1;
        }
        if (maxValue == -1 || maxValue < distance[i])
        {
            maxValue = distance[i];
        }
    }

    return maxValue;
}

// times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
int networkDelayTime1(int** times, int timesSize, int* timesColSize, int N, int K){
    int distance[MAX_NUM] = {0};
    int visited[MAX_NUM] = {0};
    for (size_t i = 1; i <= N; i++)
    {
        distance[i] = -1;
    }

    distance[K] = 0;
    for (size_t i = 1; i <= N; i++)
    {
        int next;
        int minV = -1;
        for (size_t j = 1; j <= N; j++)
        {
            if (visited[j] == 1 || distance[j] == -1)
            {
                continue;
            }
            if (minV == -1 || distance[j] < minV)
            {
                minV = distance[j];
                next = j;
            }
        }

        visited[next] = 1;
        for (size_t j = 0; j < timesSize; j++)
        {
            int src = times[j][0];
            if (src != next)
            {
                continue;
            }
            int dst = times[j][1];
            if (visited[dst] == 1)
            {
                continue;
            }
            if (distance[dst] == -1 || distance[dst] > distance[src] + times[j][2])
            {
                distance[dst] = distance[src] + times[j][2];
            }
        }
    }
    
    int maxValue = -1;
    for (size_t i = 1; i <= N; i++)
    {
        if (distance[i] == -1)
        {
            return -1;
        }
        if (maxValue == -1 || maxValue < distance[i])
        {
            maxValue = distance[i];
        }
    }

    return maxValue;
}

/*
int main()
{
    int a[][3] = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int **b = (int **)malloc(sizeof(int*) * 3);
    for (size_t i = 0; i < 3; i++)
    {
        b[i] = (int*)malloc(sizeof(int) * 3);
    }
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    
    networkDelayTime(b, 2, NULL, 4, 2);

    return 0;
}
*/