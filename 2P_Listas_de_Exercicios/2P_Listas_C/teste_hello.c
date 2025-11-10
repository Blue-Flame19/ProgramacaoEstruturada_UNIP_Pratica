#include <stdio.h>

int main() {
    // Print a message to verify the program is running
    printf("Hello, C Environment!\n");
    
    // Basic variable operations
    int a = 5;
    int b = 3;
    int sum = a + b;
    
    printf("Sum of %d and %d is: %d\n", a, b, sum);
    
    // Check if basic conditions work
    if (sum > 5) {
        printf("The sum is greater than 5\n");
    } else {
        printf("The sum is 5 or less\n");
    }
    
    return 0;
}
