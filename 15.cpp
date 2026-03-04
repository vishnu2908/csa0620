#include <stdio.h>
#include <string.h>

void findLargeGroups(char s[]) {
    int n = strlen(s);
    
    int start = 0;  // start index of current group
    
    for (int i = 1; i <= n; i++) {
        
        // If end of string OR character changes
        if (i == n || s[i] != s[start]) {
            
            int length = i - start;
            
            if (length >= 3) {
                printf("[%d,%d]\n", start, i - 1);
            }
            
            start = i;  // new group starts
        }
    }
}

int main() {
    char s[100];
    
    printf("Enter string: ");
    scanf("%s", s);
    
    printf("Large groups intervals:\n");
    findLargeGroups(s);
    
    return 0;
}
