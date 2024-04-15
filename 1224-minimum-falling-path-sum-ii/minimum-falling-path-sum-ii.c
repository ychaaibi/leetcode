int get_min(int **grid, int gridColSize, int index_col, int index_row)
{
    int min;
    int i;
    
    i = 0;
    min = INT_MAX;
    while (i < gridColSize)
    {
        if (i != index_col)
            min = (min < (grid[index_row][index_col] + grid[index_row - 1][i])) ? min : grid[index_row][index_col] + grid[index_row - 1][i];
        i++;
    }
    return (min);
}

int minFallingPathSum(int** grid, int gridSize, int* gridColSize){
    int i;
    int j;
    int min;
    
    min = INT_MAX;
    i = 0;
    while (++i < gridSize)
    {
        j = -1;
        while (++j < *gridColSize)
            grid[i][j] = get_min(grid, *gridColSize, j, i);
    }
    i = -1;
    while (++i < *gridColSize)
        min = (min < grid[gridSize - 1][i]) ? min : grid[gridSize - 1][i];
    return (min);    
}