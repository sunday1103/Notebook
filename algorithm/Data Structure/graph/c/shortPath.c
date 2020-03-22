#include <stdio.h>

#define MAX_N 100

int g_map[MAX_N][MAX_N];
int g_n;

void FindShortPath(int s)
{
    int distance[MAX_N];
    int prev[MAX_N];
    for (int i = 0; i < g_n; ++i) {
        distance[i] = -1;
        prev[i] = -1;
    }
    distance[s] = 0;
    prev[s] = s;

    int visit[MAX_N] = {0};
    for (int j = 0; j < g_n; ++j) {
        int next = 0;
        int min = -1;
        for (int i = 0; i < g_n; ++i) {
            if (visit[i] == 1 || distance[i] == -1) {
                continue;
            }
            if (min == -1 || min > distance[i]) {
                min = distance[i];
                next = i;
            }
        }
        visit[next] = 1;
        for (int k = 0; k < g_n; ++k) {
            if (g_map[next][k] == -1) {
                continue;
            }
            if (distance[k] == -1 || g_map[next][k] + distance[next] < distance[k]) {
                distance[k] = g_map[next][k] + distance[next];
                prev[k] = next;
            }
        }
    }

    for (int i = 0; i < g_n; ++i) {
        printf("%d to %d = %d | ", s, i, distance[i]);
        int p = i;
        while(p != s) {
            printf("%d <- ", p);
            p = prev[p];
        }
        printf("%d\n", s);
    }
}

void AddEdge(int u, int v, int vaule)
{
    g_map[u][v] = vaule;
    g_map[v][u] = vaule;
}

void Init()
{
    g_n = 6;
    for (int i = 0; i < g_n; ++i) {
        for (int j = 0; j < g_n; ++j) {
            g_map[i][j] = -1;
        }
    }
    int edge[][3] = {
        {0, 1, 5},
        {0, 3, 8},
        {1, 3, 6},
        {1, 2, 12},
        {3, 4, 2},
        {2, 4, 3},
        {2, 5, 1},
        {4, 5, 4}
    };
    for (int k = 0; k < sizeof(edge) / sizeof(edge[0]); ++k) {
        AddEdge(edge[k][0], edge[k][1], edge[k][2]);
    }
}

int main() {
    Init();
    FindShortPath(1);
    FindShortPath(0);
    return 0;
}
