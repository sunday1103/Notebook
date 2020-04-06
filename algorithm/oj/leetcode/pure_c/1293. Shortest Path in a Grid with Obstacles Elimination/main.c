#include <stdio.h>
#include <stdlib.h>

void bfs(char** grid, int m, int n, int x, int y, int **visited)
{
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if (visited[x][y]) {
        return;;
    }

    if (grid[x][y] == '0') {
        return;
    }

    visited[x][y] = 1;
    bfs(grid, m, n, x + 1, y, visited);
    bfs(grid, m, n, x - 1, y, visited);
    bfs(grid, m, n, x, y + 1, visited);
    bfs(grid, m, n, x, y - 1, visited);
}

/*
 * 输入:
11000
11000
00100
00011
输出: 3
 * */
int numIslands(char** grid, int gridSize, int* gridColSize){
    int **visited = (int**)malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; ++i) {
        visited[i] = (int*)malloc(sizeof(int) * gridColSize[0]);
    }
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            visited[i][j] = 0;
        }
    }

    int num = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (visited[i][j] != 0) {
                continue;
            }

            if (grid[i][j] == '0') {
                continue;
            }

            bfs(grid, gridSize, gridColSize[0], i, j, visited);
            num++;
        }
    }

    for (int i = 0; i < gridSize; ++i) {
        free(visited[i]);
    }
    free(visited);

    return num;
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
    numIslands(grid, gridSize, gridColSize);
    return 0;
}
