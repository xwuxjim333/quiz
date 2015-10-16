/* FIXME: Implement! */
#include <stdio.h>
#include <time.h>

#define length 50

char smallest_character(char str[], char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > c) {
            return str[i];
        }
        i++;
    }

//If no such character exists, return the smallest character in the array. 
    return str[0];
}

int main()
{
    char str[length];
    char c, out;
    clock_t start, end;
    double time;

    printf("Input a sorted character array: ");
    fgets(str, length, stdin);
    printf("Input a character: ");
    scanf("%c", &c);
    fflush(stdin);

    start = clock();
    out = smallest_character(str, c);
    end = clock();
    time = (end - start) / (double)(CLOCKS_PER_SEC);

    printf("Output: %c\n", out);
    printf("execution time of smallest_character() : %lf sec\n", time);
    return 0;
}
