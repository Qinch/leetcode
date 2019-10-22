/*************************************************************************
 > File Name: leetcode_221.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-22 Time:10:49:52.
 ************************************************************************/
int isSquare(char **matrix, int i, int j, int len)
{
    int ret = 1;
    for (int k = 0; k < len; ++k) {
        if (matrix[i][j - k] == '0' || matrix[i - k][j] == '0')
        {
            ret = 0;
            break;
        }

    }
    return ret;    
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    
    int **dp = malloc(sizeof(*dp) * matrixSize); 
    for (int i = 0; i < matrixSize; ++i) {
        int size = sizeof(int) * (*matrixColSize);
        dp[i] = malloc(size);
        memset(dp[i], 0, size);
    }
    
    
    int max = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            // dp
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int last = dp[i - 1][j - 1];
                    for (int k = last + 1; k > 0; k-- ) {
                        int ret = isSquare(matrix, i, j, k);
                        if (ret == 1) {
                            dp[i][j] = k;
                            break;
                        }
                    }
                }
                
                int tmp = dp[i][j];
                max = max < tmp ? tmp : max;
                
            }
            
        }

    }

    return max * max;
}
