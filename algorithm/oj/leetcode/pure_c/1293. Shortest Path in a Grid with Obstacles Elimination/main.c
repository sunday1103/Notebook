#include <stdio.h>
#include <stdlib.h>

/*
 * 输入：
grid =
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]],
k = 1
输出：6
 */

void Find(int** grid, int m, int n, int x, int y, int dis, int k, int ***visited, int *distance)
{
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }

    if (dis >= *distance) {
        return;
    }

    if (x == m - 1 && y == n - 1) {
        *distance = dis;
        return;
    }

    if (grid[x][y] == 1) {
        if (k == 0) return;
        k = k - 1;
    }

    if (visited[x][y][k] == 1) {
        return;
    }

    visited[x][y][k] = 1;

    Find(grid, m, n, x, y + 1, dis + 1, k, visited, distance);
    Find(grid, m, n, x + 1, y, dis + 1, k, visited, distance);
    Find(grid, m, n, x, y - 1, dis + 1, k, visited, distance);
    Find(grid, m, n, x - 1, y, dis + 1, k, visited, distance);
}

int shortestPath(int** grid, int gridSize, int* gridColSize, int k){
    int distance = 0x0FFFFFFF;
    if (gridSize + gridColSize[0] - 2 < k) {
        k = gridSize + gridColSize[0] - 2;
    }
    int ***visited= (int***)malloc(sizeof(int**) * gridSize);
    for (int i = 0; i < gridSize; ++i) {
        visited[i] = (int**)malloc(gridColSize[0] * sizeof(int*));
        for (int j = 0; j < gridColSize[0]; ++j) {
            visited[i][j] = (int*)malloc(sizeof(int) * (k + 1));
        }
    }
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            for (int l = 0; l < k + 1; ++l) {
                visited[i][j][l] = 0;
            }
        }
    }
    Find(grid, gridSize, gridColSize[0], 0, 0, 0, k, visited, &distance);
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            free(visited[i][j]);
        }
        free(visited[i]);
    }
    free(visited);
    return distance == 0x0FFFFFFF ? -1 : distance;
}

int main() {
#define M 9
#define N 34

    int grid1[M][N] = {{0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1},
                       {1,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,1,0,1,0,0,0},
                       {1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0},
                       {0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0},
                       {1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
                       {0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1},
                       {0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,0,1,0},
                       {1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,1,0,1},
                       {1,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0}};

    int **grid = (int**)malloc(sizeof(int*) * M);
    for (int i = 0; i < M; ++i) {
        grid[i] = (int*)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = grid1[i][j];
        }
    }
    int gridSize = M;
    int gridColSize[M] = {N};
    shortestPath(grid, gridSize, gridColSize, 283);
    return 0;
}
