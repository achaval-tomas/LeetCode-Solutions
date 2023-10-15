int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int grid[obstacleGridSize][*obstacleGridColSize];
    
    for (int i = 0; i<*obstacleGridColSize; ++i){
        grid[0][i] = (obstacleGrid[0][i] || (i>0 && grid[0][i-1] == 0)) ? 0 : 1;
    }
    for (int i = 1; i<obstacleGridSize; ++i){
        grid[i][0] = (obstacleGrid[i][0] || (i>0 && grid[i-1][0] == 0)) ? 0 : 1;
    }
    for (int i = 1; i<obstacleGridSize; ++i){
        for (int j = 1; j<*obstacleGridColSize; ++j){
            grid[i][j] = obstacleGrid[i][j] ? 0 : grid[i][j-1] + grid[i-1][j];
        }    
    }

    return grid[obstacleGridSize-1][*obstacleGridColSize-1];
}