#include <stdio.h>

int main() {
    int number, reversedNumber = 0, remainder;

    // Prompt the user for input
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Reverse the number
    while (number != 0) {
        remainder = number % 10; // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder; // Build the reversed number
        number /= 10; // Remove the last digit from the original number
    }

    // Output the reversed number
    printf("Reversed Number: %d\n", reversedNumber);
    return 0;
}
