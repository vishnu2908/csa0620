#include <stdio.h>

int climbStairs(int n) {
    
    if (n <= 1)
        return 1;
    
    int prev1 = 1;  // ways to reach step 0
    int prev2 = 1;  // ways to reach step 1
    int current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    
    return prev2;
}

int main() {
    int n;
    
    printf("Enter number of steps: ");
    scanf("%d", &n);
    
    int result = climbStairs(n);
    
    printf("Number of distinct ways: %d\n", result);
    
    return 0;
}
