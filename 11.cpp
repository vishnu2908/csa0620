#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int findPaths(int m, int n, int N, int startRow, int startColumn) {
    
    // Allocate memory for dp arrays
    long dp[m][n];
    long temp[m][n];
    
    // Initialize dp array
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = 0;
    
    dp[startRow][startColumn] = 1;
    
    long count = 0;
    
    for(int step = 0; step < N; step++) {
        
        // Reset temp array
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                temp[i][j] = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(dp[i][j] > 0) {
                    long ways = dp[i][j];
                    
                    // Move Up
                    if(i == 0)
                        count = (count + ways) % MOD;
                    else
                        temp[i-1][j] = (temp[i-1][j] + ways) % MOD;
                    
                    // Move Down
                    if(i == m - 1)
                        count = (count + ways) % MOD;
                    else
                        temp[i+1][j] = (temp[i+1][j] + ways) % MOD;
                    
                    // Move Left
                    if(j == 0)
                        count = (count + ways) % MOD;
                    else
                        temp[i][j-1] = (temp[i][j-1] + ways) % MOD;
                    
                    // Move Right
                    if(j == n - 1)
                        count = (count + ways) % MOD;
                    else
                        temp[i][j+1] = (temp[i][j+1] + ways) % MOD;
                }
            }
        }
        
        // Copy temp to dp
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = temp[i][j];
    }
    
    return count;
}

int main() {
    int m = 2, n = 2, N = 2;
    int startRow = 0, startColumn = 0;
    
    int result = findPaths(m, n, N, startRow, startColumn);
    
    printf("Number of ways: %d\n", result);
    
    return 0;
}
