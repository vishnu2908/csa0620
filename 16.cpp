#include <stdio.h>

#define MAX 101

double champagneTower(int poured, int query_row, int query_glass) {
    
    double dp[MAX][MAX] = {0};
    
    dp[0][0] = poured;
    
    for (int i = 0; i < query_row; i++) {
        for (int j = 0; j <= i; j++) {
            
            if (dp[i][j] > 1.0) {
                double overflow = (dp[i][j] - 1.0) / 2.0;
                
                dp[i+1][j] += overflow;
                dp[i+1][j+1] += overflow;
                
                dp[i][j] = 1.0;  // glass becomes full
            }
        }
    }
    
    if (dp[query_row][query_glass] > 1.0)
        return 1.0;
    else
        return dp[query_row][query_glass];
}

int main() {
    int poured, row, glass;
    
    printf("Enter poured cups: ");
    scanf("%d", &poured);
    
    printf("Enter query row and glass (0-indexed): ");
    scanf("%d %d", &row, &glass);
    
    double result = champagneTower(poured, row, glass);
    
    printf("Amount in glass: %.6f\n", result);
    
    return 0;
}
