#include <stdlib.h>
#include <unistd.h>

// Function to calculate the length of a string
int length(char *s) {
    int l = 0;
    while (s[l])
        l++;
    return l;
}

// Function to perform infinite addition of two numbers represented as strings
void infiniteAddition(char *x, char *y) {
    // Handle sign and leading zeros for x
    int signX = 1, signY = 1;
    if (x[0] == '-') {
        signX = -1;
        x++;
    }
    while (*x == '0')
        x++;

    // Handle sign and leading zeros for y
    if (y[0] == '-') {
        signY = -1;
        y++;
    }
    while (*y == '0')
        y++;

    // Handle special case where one number is zero
    if (x[0] == '0' && length(x) == 1) {
        if (signY == -1 && !(y[0] == '0' && length(y) == 1))
            write(1, "-", 1);
        write(1, y, length(y));
        return;
    }
    if (y[0] == '0' && length(y) == 1) {
        if (signX == -1)
            write(1, "-", 1);
        write(1, x, length(x));
        return;
    }

    // Determine the length of the result and allocate memory
    int resultLength = (length(x) > length(y) ? length(x) : length(y)) + 1;
    char *result = malloc(sizeof(char) * (resultLength + 1));
    result[resultLength] = '\0';

    // Initialize the result with zeros
    for (int i = 0; i < resultLength; i++)
        result[i] = '0';

    // Swap x and y if necessary based on signs and lengths
    if (signX != signY) {
        int shouldSwap = 0;
        if (length(x) == length(y)) {
            for (int i = 0; i < length(x); i++) {
                if (y[i] > x[i]) {
                    shouldSwap = 1;
                    break;
                }
            }
        } else {
            if (length(y) > length(x))
                shouldSwap = 1;
        }
        if (shouldSwap) {
            char *temp = x;
            x = y;
            y = temp;
            int tmpSign = signX;
            signX = signY;
            signY = tmpSign;
        }
    }

    // Perform addition
    for (int i = 0; i < resultLength - 1; i++) {
        int digitX = (i < length(x)) ? x[length(x) - i - 1] - '0' : 0;
        int digitY = (i < length(y)) ? y[length(y) - i - 1] - '0' : 0;

        if (signX == signY) {
            int sum = digitX + digitY + (result[resultLength - i - 1] - '0');
            result[resultLength - i - 1] = (sum % 10) + '0';
            result[resultLength - i - 2] = (sum / 10) + '0';
        } else {
            int difference = digitX - digitY + (result[resultLength - i - 1] - '0');
            result[resultLength - i - 1] = ((difference >= 0 ? difference : 10 + difference) % 10) + '0';
            result[resultLength - i - 2] = (difference >= 0 ? 0 : -1) + '0';
        }
    }

    // Remove leading zeros from the result
    while (*result && *result == '0')
        result++;

    // Output the result
    if (signX == -1 && (*result))
        write(1, "-", 1);
    if (!(*result))
        result--;
    write(1, result, length(result));
}

int main(int argc, char **argv) {
    if (argc == 3)
        infiniteAddition(argv[1], argv[2]);
    write(1, "\n", 1);
}