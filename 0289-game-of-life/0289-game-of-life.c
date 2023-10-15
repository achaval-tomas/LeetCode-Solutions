void gameOfLife(int** board, int boardSize, int* boardColSize){
    int ans[boardSize][*boardColSize];
    for (int i = 0; i<boardSize;++i){
        for(int j = 0; j<*boardColSize; ++j){
            int neighs = 0;
            neighs += (i>0) ? board[i-1][j] : 0;
            neighs += (i>0 && j+1<*boardColSize) ? board[i-1][j+1] : 0;
            neighs += (i>0 && j>0) ? board[i-1][j-1] : 0;
            neighs += (j>0) ? board[i][j-1] : 0;
            neighs += (j+1  < *boardColSize) ? board[i][j+1] : 0;
            neighs += (i+1<boardSize && j   < *boardColSize) ? board[i+1][j] : 0;
            neighs += (i+1<boardSize && j+1 < *boardColSize) ? board[i+1][j+1] : 0;
            neighs += (i+1<boardSize && j>0) ? board[i+1][j-1] : 0;
            if (neighs < 2 || neighs > 3) {
                ans[i][j] = 0;
            } else if (!board[i][j] && neighs == 3) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i<boardSize;++i){
        for(int j = 0; j<*boardColSize; ++j){
            board[i][j] = ans[i][j];
        }
    }
}