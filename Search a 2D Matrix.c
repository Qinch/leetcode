bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i=matrixRowSize-1;//��;
    int j=0;//��;
    while((i>=0)&&(j<matrixColSize))
    {
        if(matrix[i][j]>target)
            i--;
        else if(matrix[i][j]<target)
            j++;
        else
            return true;
    }
    return false;
    
}