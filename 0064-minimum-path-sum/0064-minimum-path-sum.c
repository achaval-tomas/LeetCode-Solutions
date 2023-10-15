int minPathSum(int** grid, int gridSize, int* gridColSize){
    int path[gridSize][*gridColSize];
    path[0][0] = grid[0][0];

    for (int i = 1; i<*gridColSize; ++i){
        path[0][i] = grid[0][i] + path[0][i-1];
    }
    for (int i = 1; i<gridSize; ++i){
        path[i][0] = grid[i][0] + path[i-1][0];
    }

    for (int i = 1; i<gridSize; ++i){
        for (int j = 1; j<*gridColSize; ++j){
            path[i][j] = grid[i][j] + fmin(path[i][j-1], path[i-1][j]);
        }
    }

    return path[gridSize-1][*gridColSize-1];
}